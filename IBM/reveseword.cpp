#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;


int main(){

  string name = "Patil vamanrao Tejas";
              // 01234567890123456789
  stack<string> result;

  int i=0 ,s=0;
  while(i < name.length()){
    string pass = "";
    while(name[i] != ' ' && i < name.length()){
      pass+=name[i];
      i++;
    }
    
    result.push(pass);
    i++;
  }

  while(!result.empty()){
    std::cout << result.top()<<" ";
    result.pop();
  }
  std::cout << std::endl;


  return 0;
}
