#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    double min_pair=A[0]+A[1]/2.0;
    int min_index=0;

    for(unsigned int i=0;i<A.size()-2;i++){

        if((A[i]+A[i+1])/2 < min_pair){
            min_pair=(A[i]+A[i+1])/2;
            min_index=i;
            }
        if((A[i]+A[i+1]+A[i+2])/3 < min_pair){
            min_pair=(A[i]+A[i+1]+A[i+2])/3;
            min_index=i;
            }
        }

    if((A[-1]+A[-2])/2 < min_pair){
        min_pair=(A[-1]+A[-2])/2;
        min_index=A.size()-2;
        }

    return min_index;
}

int main(){

  vector<int> A = {4, 2, 2, 5, 1, 5, 8};



  return 0
}
