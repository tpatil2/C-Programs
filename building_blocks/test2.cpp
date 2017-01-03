// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <iostream>
#include <string>

using namespace std;

int find_sum(int spaces){

  int length=0;
    if(spaces==0){
      return length;
    }else{
      int sum=12;//modified wrt to values of spaces as in given example
      for(int i=0;i<spaces;i++){
        length+=sum;
        sum++;
      }
    }

  return length+1;
}

// find number of spaces before ext file
int find_length(string str,string ext){

  int pos;
  pos = str.find(ext);
  int space=0;
  if(pos!=-1){

  while(str[pos]!=' '){
    pos--;
  }
  while(str[pos]==' '){
    pos--;
    space++;
  }
  }

  return find_sum(space);
}


int solution(string &S) {
    // write your code in C++11 (g++ 4.8.2)
    //replace \n with \t
    unsigned int total=0;
    for(unsigned int i=0;i<S.length();i++){

        if(S[i]=='\n'){
              S[i]='/';
            }
        } S.insert(0,"/");

      for(size_t i=S.length()-4;i>0;i--){
      string ext=S.substr(i,4);
      if(ext==".png"|| ext==".gif"){
        total+=find_length(S,ext);
      }
    }

     for(size_t i=S.length()-5;i>0;i--){
      string ext=S.substr(i,5);
      if(ext==".jpeg"){
        total+=find_length(S,ext);
      }
    }


    return total;
}
