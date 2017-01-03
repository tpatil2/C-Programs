#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void print(vector<int> vec){

for(auto it=vec.begin();it<vec.end();it++){
  std::cout << *it << " " ;
}

}


vector<int> cal_multi(vector<int> A,vector<int> B){
  vector<int> result;

  int size_a=A.size();
  int size_b=B.size();
  int i=0,j=0;
  bool flag=true;


  lable:while(i < size_a && j<size_b){
    result.push_back(A[i++]*B[j++]);
  }

  if(i==size_a && flag==true){
    i=0;
    flag=false;
    goto lable;
  }

  if(j==size_b && flag==true){
    j=0;
    flag=false;
    goto lable;
  }



  return result;
}



int main(){

  vector<int> A = {1,2,3,4,5};
  vector<int> B = {1,2,3};

  vector<int> Result;
  std::cout << "result is" << std::endl;
  Result=cal_multi(A,B);
  print(Result);


  return 0;
}
