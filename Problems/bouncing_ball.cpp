#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> &A, int skip){

  int count;
  for(int i:A) std::cout << i <<" ";



  return count;
}

int main(){
  vector<int> A;

  for(int i=0;i<100;i++){
    A.push_back(i);
  }

  std::cout << "Skip count is : "<< solution(A,3) << std::endl;
  return 0;
}
