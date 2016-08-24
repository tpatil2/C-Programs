#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    int N = A.size();
    double min_avg=A[0]+A[1]/2.0;
    int min_index=0;

    for(unsigned int i=2;i<N;i++){

      double avg1 = (A[i - 1] + A[i]) / 2.0;
      double avg2 = (A[i - 2] + A[i - 1] + A[i]) / 3.0;

        if (avg1 < min_avg){
            min_index = i - 1;
            min_avg = avg1;
        }
        if (avg2 < min_avg){
            min_index = i - 2;
            min_avg = avg2;
        }

    }


    return min_index;
}

int main(){

  vector<int> A = {4, 2, 2, 5, 1, 5, 8};

std::cout << "Starting index of pair is "<<solution(A) << std::endl;

  return 0;
}
