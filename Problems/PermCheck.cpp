// Check whether array A is a permutation.
//Codility TASK free trial
/*NOTE: Task Description
A non-empty zero-indexed array A consisting of N integers is given.
A permutation is a sequence containing each element from 1 to N once, and only once.
For example, array A such that:
    A[0] = 4
    A[1] = 1
    A[2] = 3
    A[3] = 2
is a permutation, but array A such that:
    A[0] = 4
    A[1] = 1
    A[2] = 3
is not a permutation, because value 2 is missing.
The goal is to check whether array A is a permutation.
Write a function:
    int solution(vector<int> &A);
that, given a zero-indexed array A, returns 1 if array A is a permutation and 0 if it is not.
*/

#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)

    unsigned int temp = 0;
    unsigned int n = A.size();

    for(unsigned int i=0; i<n;i++){
            temp = temp ^ (i+1) ^ A[i];
        }

    if(temp==0) return 1;

return 0;

}

int main(){

  vector<int> A = {1,2,3,4,5,6,8};

  if(solution(A)) std::cout << "It is permutation" << std::endl;
    else std::cout << "It is not permutation" << std::endl;

}
