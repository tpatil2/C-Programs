#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)

    int size = A.size();
    vector<int> cross;
    bool zero = true;

    if(A[0]==0) {
        cross.push_back(A[0]);
        }else{
            cross.push_back(0);
            zero = false;
            }

    for(int i=1 ; i<size; i++){
        if(zero==true){
            if(A[i]==1){
                for(unsigned int it=0;it<cross.size();it++){
                        cross[it]+=1;
                    }
                }else{
                    cross.push_back(A[i]);
                    }
        }else if(A[i]==0){
                for(unsigned int it=0;it<cross.size();it++){
                    cross[it]+=1;
                    }
                }else{
                    cross.push_back(0);
                }
    }

    int sum=0;
      for(unsigned int t=0;t<cross.size();t++){
                   sum+=cross[t];
                    }

    return sum;
}

int main(){

  vector<int> A = {0,0};

  std::cout << "Total Pairs are : "<<solution(A)<< std::endl;


  return 0;
}
