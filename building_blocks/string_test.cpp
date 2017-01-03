#include <iostream>
#include <string>


using namespace std;
int main(){

  char str[] = "tejastejas";
  string str1="TEJAS";

  int n = strlen(str);

  std::cout << "str is : "<< *str << std::endl;
  std::cout << "str is : "<< str << std::endl;
  std::cout << "str length is : "<< n << std::endl;

  sort(str,str+n);
  std::cout << "str sorted is : "<< str << std::endl;



  return 0;
}
