#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
  //NOTE: REF : https://codesays.com/2014/solution-to-passing-cars-by-codility/
  int count = 0;
  int passing  = 0;

 // for each value in the vector A
  for (int i : A)
  {
      if (i == 1) {
          passing += count;
          if(passing > 1000000000)
              return -1;
      }else
          count++;
  }
  return passing;
}

int main(){

  vector<int> A = {1,0,1};
  std::cout << "Total Pairs are : "<<solution(A)<< std::endl;


  return 0;
}
