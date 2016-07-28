#include <iostream>
#include <string>
#define LIMIT 100

using namespace std;

string missing_num(int arr[], int size){
  bool present[LIMIT]={false};

  for(int i=0;i<size;i++){
    if(arr[i]<LIMIT) present[arr[i]]=true;
  }

  string str="(";

  int i=0;
  while(i<LIMIT){

      if(present[i]==false){
        int j =i+1;
      while (j<LIMIT && present[j]==false) {
        j++;
      }

      if(i+1 == j){ str+=to_string(i)+",";}
      else{
        str+=to_string(i)+"-"+to_string(j-1)+",";
      }
      i=j;
    }
    i++;
  }
  str+=")";

  return str;

}


int main(){

int arr[]={2,5,9,11,33,56,77};

int size= sizeof(arr)/sizeof(arr[0]);

std::cout << "size of array is : "<< size << std::endl;

std::cout << "Missing mumber range is:\n" <<missing_num(arr,size)<< std::endl;


  return 0;
}
