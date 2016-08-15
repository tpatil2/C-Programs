#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solutions(int N, vector<int> &A){

  // write your code in C++11 (g++ 4.8.2)
      vector <int> counter;
      counter.resize(N,0);
      int Max=0;

     for( unsigned int i=0;i<A.size();i++){
          if(A[i]>N){
              fill(counter.begin(),counter.end(),Max);
            }
          else {
              counter[A[i]-1]++;
            }
          Max = max(Max, counter[A[i]-1]);
          }

      return counter;
}

int main(){

  vector<int> A = {3, 4, 4, 6, 1, 4, 4};
  vector<int> opt;
  opt=solutions(1,A);

  for(auto it=opt.begin();it!=opt.end();it++){
    std::cout << *it <<" ";
  }
  std::cout << std::endl;
  return 0;
}
