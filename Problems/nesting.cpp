/*
A string S consisting of N characters is called properly nested if:

        S is empty;
        S has the form "(U)" where U is a properly nested string;
        S has the form "VW" where V and W are properly nested strings.

For example, string "(()(())())" is properly nested but string "())" isn't.

Write a function:

    int solution(string &S);

*/

#include <iostream>
#include <string>
using namespace std;

int solution(string &S) {
    // write your code in C++11 (g++ 4.8.2)
    int size=S.size();
    int count=0;

    for(int i=0;i<size;i++){
        if(S[i]=='(') count++;
        else {
            count--;
            if(count<0) return 0;
            }
        }

        if(count != 0) return 0;

 return 1;
}

int main(){

  string str="(()(())()))";

  if(solution(str)) std::cout << "Yes its nested" << std::endl;
    else std::cout << "Not nested" << std::endl;
  return 0;
}
