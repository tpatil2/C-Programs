#include <iostream>

using namespace std;



// you can use includes, for example:
// #include <algorithm>
#include <string>
using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S) {
    // write your code in C++11 (g++ 4.8.2)
    int size = S.size();
    int counter1=0;
    int counter2=0;
    int counter3=0;

    for(int i=0;i<size;i++){
        if(S[i]=='(') counter1++;
        else if(S[i]=='{') counter2++;
        else if(S[i]== '[') counter3++;
        else if(S[i]==')') counter1--;
        else if(S[i]=='}') counter2--;
        else if(S[i]==']') counter3--;

            if(counter1<0 || counter2<0 || counter3<0 ) return 0;
             if(counter1<counter2 || counter1<counter3) return 0;

        }
    if(counter1==0 && counter2==0 && counter3==0) return 1;

    return 0;

}


int main(){


    string str="{[()()]}";

    if(solution(str)) std::cout << "Yes its nested" << std::endl;
      else std::cout << "Not nested" << std::endl;


  return 0;
}
