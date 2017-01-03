#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> vec){

for(auto it=vec.begin();it<vec.end();it++){
  std::cout << *it << " " ;
}

}


vector<int> cal_intersection(vector<int> A,vector<int> B){

    vector<int> result;
    for(auto it=A.begin();it!=A.end();it++){
      for(auto it2=B.begin();it2!=B.end();it2++){
          if(*it==*it2){
            result.push_back(*it);
            break;
          }
        }
      }

  return result;
}

vector<int> cal_union(vector<int> A,vector<int> B){

  vector<int> result;
  bool flag=false;
  for(auto it=A.begin();it!=A.end();it++){

    for(auto it2=B.begin();it2!=B.end();it2++){
        if(*it==*it2){
          flag=true;
        }
      }
      if(flag==0) B.push_back(*it);
      flag=false;
    }

  return B;
}


int main(){

  vector<int> A = {2,4,3,5,6};
  vector<int> B = {1,2,6,5,0};
  vector<int> Result;

  std::cout << "intersection" << std::endl;
  Result=cal_intersection(A,B);
  print(Result);

  std::cout << "union" << std::endl;
    Result=cal_union(A,B);
    print(Result);




  return 0;
}
