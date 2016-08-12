/*
A non-empty zero-indexed array A consisting of N integers is given. Array A represents numbers on a tape.
Any integer P, such that 0 < P < N, splits this tape into two non-empty parts: A[0], A[1], ..., A[P − 1] and A[P], A[P + 1], ..., A[N − 1].
The difference between the two parts is the value of: |(A[0] + A[1] + ... + A[P − 1]) − (A[P] + A[P + 1] + ... + A[N − 1])|
In other words, it is the absolute difference between the sum of the first part and the sum of the second part.
For example, consider array A such that:
  A[0] = 3
  A[1] = 1
  A[2] = 2
  A[3] = 4
  A[4] = 3
We can split this tape in four places:
        P = 1, difference = |3 − 10| = 7
        P = 2, difference = |4 − 9| = 5
        P = 3, difference = |6 − 7| = 1
        P = 4, difference = |10 − 3| = 7
Write a function:
    int solution(vector<int> &A);
that, given a non-empty zero-indexed array A of N integers, returns the minimal difference that can be achieved.
For example, given:
  A[0] = 3
  A[1] = 1
  A[2] = 2
  A[3] = 4
  A[4] = 3
the function should return 1, as explained above.
Assume that:
        N is an integer within the range [2..100,000];
        each element of array A is an integer within the range [−1,000..1,000].

Complexity:
        expected worst-case time complexity is O(N);
        expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).

Elements of input arrays can be modified.
Copyright 2009–2016 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/// you can use includes, for example:

#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>
#include <vector>
#include <iterator>
#include <climits>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

using namespace std;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    vector<int>::iterator it;
    vector<long long> reverse_sum;
    unsigned int size;
    size=A.size();
    reverse_sum.reserve(size-1);
    reverse_sum.push_back(*(A.end()-1));
    long long sumA = *A.begin();
    long long result = LLONG_MAX;
    int n=0;
    int i=0;

    for(it=A.end()-2;it!=A.begin();it--){
      reverse_sum.push_back(reverse_sum[n] + *it);
      n++;
    }// ( 6,11,15,18,20,)

    while(n>-1){
        if(i!=0){
          sumA += *(A.begin()+i);
        }
        i++;
        result=min(result,abs(sumA - reverse_sum[n]));
        n--;
    }

return result;
}


int main(){

  vector<int> A = {1,2,3,4,5,6};

  std::cout << "val is " << solution(A)<<std::endl;

  return 0;
}
