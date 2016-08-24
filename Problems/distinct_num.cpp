/*Write a function
int solution(vector<int> &A);
that, given a zero-indexed array A consisting of N integers, returns the number of distinct values in array A.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    if(A.size()==1) return 1;

     sort(A.begin(),A.end());
     int count=0;

     for(auto it=A.begin();it!=A.end();it++){

            while(*it == *(it+1)){
                it++;
                }
            count++;
         }

    return count;
}

int main(){

  vector<int> A = {2,1,3,2,1,1,2,6,8,6,4,2,1};

  std::cout << "Number of Distince elements are : "<<
  solution(A) << std::endl;

  return 0;
}
