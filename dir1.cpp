#include <iostream>
#include <string>

using namespace std;

int find_sum(int spaces){
  int length=0;
    if(spaces==0){
      return length;
    }else{
      int sum=4;
      for(int i=0;i<spaces;i++){
        length+=sum;
        sum++;
      }
    }

  return length+1;
}

void find_length(string str,string ext){
  size_t pos;
  pos = str.find(ext);
  if(pos!=-1){
  int space=0;
  while(str[pos]!='\t'){
    pos--;
  }
  while(str[pos]=='\t'){
    pos--;
    space++;
  }
  std::cout << "Length of "<< ext <<" is: "<<find_sum(space) << std::endl;
  }
}

int main(){

  string str = "dir1\n	dir11\n		ak.txt\n	dir12\n		dir112\n		ab.jpg\ndir2\n	cd.png";

  std::cout << str << std::endl;
//removed all newline from string
  for(int i=0;i<str.length();i++){
    int k=0;
    if(str[i]=='\n'){
      str.erase(i,1);
      i--;
    }
  }

  for(size_t i=str.length()-4;i>0;i--){
      string ext=str.substr(i,4);
      if(ext==".png"|| ext==".jpg"){
        find_length(str,ext);
      }
  }
  return 0;
}
