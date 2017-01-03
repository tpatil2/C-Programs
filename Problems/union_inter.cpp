#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void print(vector<int> vec){

for(auto it=vec.begin();it<vec.end();it++){
  std::cout << *it << " " ;
}

}


vector<int> cal_intersection(vector<int> A,vector<int> B){

  sort (A.begin(), A.end());
  sort (B.begin(), B.end());

  int size_a = A.size();
  int size_b = B.size();
  int i = 0, j = 0;

  vector<int> result;

 while (i < size_a && j < size_b)
 {
   if (A[i] < B[j])
     i++;
   else if (A[j] < B[i])
     j++;
   else
   {
     result.push_back(B[j++]);
     i++;
   }
 }

  return result;
}

vector<int> cal_union(vector<int> A,vector<int> B){

  sort (A.begin(), A.end());
  sort (B.begin(), B.end());

  int i = 0, j = 0;
  int size_a = A.size();
  int size_b = B.size();

  vector<int> result;

    while (i < size_a && j < size_b)
    {
      if (A[i] < B[j])
      result.push_back(A[i++]);
      else if (A[j] < B[i])
          result.push_back(B[j++]);
      else
      {
          result.push_back(B[j++]);
        i++;
      }
    }

    /* Print remaining elements of the larger array */
    while(i < size_a)
  result.push_back(A[i++]);
    while(j < size_b)
  result.push_back(B[j++]);

  return result;
  
}


int main(){

  vector<int> A = {2,4,3,5,6,2,5};
  vector<int> B = {1,2,6,5,0,0,0,2,5};
  vector<int> Result;

  std::cout << "intersection" << std::endl;
  Result=cal_intersection(A,B);
  print(Result);

    std::cout << "union" << std::endl;
    Result=cal_union(A,B);
    print(Result);




  return 0;
}
