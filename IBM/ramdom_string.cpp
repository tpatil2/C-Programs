#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>

using namespace std;

int main(){

  int len;
  int num;
  string result = "";

  cout<<"please enter length of string";
  cin>>len;
  srand(time(0));

  for(int i=0 ;i<len;i++){

    num = rand() % 26 + 65;
    std::cout << num << std::endl;
    result += char(num);

  }

  std::cout << result << std::endl;

  return 0;
}
