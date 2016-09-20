/*
Task description

A non-empty zero-indexed array A consisting of N integers is given. The product of triplet (P, Q, R) equates to A[P] * A[Q] * A[R] (0 ≤ P < Q < R < N).

For example, array A such that:
  A[0] = -3
  A[1] = 1
  A[2] = 2
  A[3] = -2
  A[4] = 5
  A[5] = 6

contains the following example triplets:

        (0, 1, 2), product is −3 * 1 * 2 = −6
        (1, 2, 4), product is 1 * 2 * 5 = 10
        (2, 4, 5), product is 2 * 5 * 6 = 60

Your goal is to find the maximal product of any triplet.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    if(A.size() < 3) return 0;
     sort(A.begin(),A.end());
     int N = A.size();
     int Max = max(A[0]*A[1]*A[N-1] , A[N-1]*A[N-2]*A[N-3]);

    return Max;
}


int main(){

  vector<int> A = {2,1,3,2,1,1,2,6,8,6,4,2,1};

  std::cout << "Max product of triplet is : "<<
  solution(A) << std::endl;

  return 0;
}
