/*
A zero-indexed array A consisting of N integers is given. A triplet (P, Q, R) is triangular if 0 ≤ P < Q < R < N and:

        A[P] + A[Q] > A[R],
        A[Q] + A[R] > A[P],
        A[R] + A[P] > A[Q].

For example, consider array A such that:
  A[0] = 10    A[1] = 2    A[2] = 5
  A[3] = 1     A[4] = 8    A[5] = 20

Triplet (0, 2, 4) is triangular.

Write a function:

    int solution(vector<int> &A);

that, given a zero-indexed array A consisting of N integers, returns 1 if there exists a triangular triplet for this array and returns 0 otherwise.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    sort(A.begin(),A.end());
     int N=A.size();
    if(N<3) return 0;

    for(auto it=A.begin();it<A.end()-2;it++){

        if(*it + *(it+1) > *(it+2)) return 1;

        }

    return 0;

}

int main(){

  vector<int> A = {3,3,5,7,3,8,0,55,3,2,24};

  if(solution(A)) std::cout << "YES" << std::endl;

  return 0;
}
