#include <iostream>
#include <string>

using namespace std;

bool is_Unique(string str){

    bool arr[256] ={false};

    for(int i=0; i<str.length();i++){

      int val = str.at(i);

      if(arr[val]==false) arr[val]=true;

      else return false;
    }

return true;

}


int main(){

  string str;
  cout<<"please Enter your stirng"<<endl;
  cin>>str;

  if(is_Unique(str)){
    std::cout << "String is unique" << std::endl;
  }else {
    std::cout << "String is not unique" << std::endl;
  }

  return 0;

}
