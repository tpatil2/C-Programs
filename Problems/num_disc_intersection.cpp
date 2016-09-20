/*
We draw N discs on a plane. The discs are numbered from 0 to N − 1. A zero-indexed array A of N non-negative integers, specifying the radiuses of the discs, is given. The J-th disc is drawn with its center at (J, 0) and radius A[J].

We say that the J-th disc and K-th disc intersect if J ≠ K and the J-th and K-th discs have at least one common point (assuming that the discs contain their borders).

The figure below shows discs drawn for N = 6 and A as follows:
  A[0] = 1
  A[1] = 5
  A[2] = 2
  A[3] = 1
  A[4] = 4
  A[5] = 0

There are eleven (unordered) pairs of discs that intersect, namely:

        discs 1 and 4 intersect, and both intersect with all the other discs;
        disc 2 also intersects with discs 0 and 3.

Write a function:

    int solution(vector<int> &A);

that, given an array A describing N discs as explained above, returns the number of (unordered) pairs of intersecting discs. The function should return −1 if the number of intersecting pairs exceeds 10,000,000.

Given array A shown above, the function should return 11, as explained above.

*/
//REF: https://codesays.com/2014/solution-to-beta2010-number-of-disc-intersections-by-codility/

#include <iostream>
#include <vector>
#include <utility>      // std::pair
#include <algorithm>

using namespace std;


int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
	int len = A.size();
	if (0 == len)return 0;

	vector<std::pair<long long, long long> > intervals;

	for (int i = 0; i < len; ++i)
		intervals.push_back(make_pair(i - (long long)A[i], i + (long long)A[i]));
	sort(intervals.begin(), intervals.end());

  for(int i=0;i<len;i++){
    std::cout << "first : "<<intervals[i].first<<"  second: "<<intervals[i].second << std::endl;
  }


	int l, h, m, count=0;
	for (int i = 0; i < len - 1; ++i)
	{
		l = i + 1;
		h = len - 1;
		while (l <= h)
		{
			m = l + (h - l) / 2;
			if (intervals[i].second >= intervals[m].first)
				l = m + 1;
			else
				h = m - 1;
		}
		count += l - 1 - i;
		if (count > 10000000)
			return -1;
	}
	return count;

}

int main(){

  vector<int> A = {1,5,2,1,4,0};

  std::cout << "number of disc intersection is : "<<
  solution(A) << std::endl;

  return 0;
}
