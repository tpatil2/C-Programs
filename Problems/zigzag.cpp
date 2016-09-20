#include <iostream>
#include <algorithm>

using namespace std;


void print(int array[], int n){

    std::cout << "array is"<< std::endl;
    for(int i=0;i<n;i++){
      std::cout << array[i]<< " ";
    }

    std::cout << std::endl;
}


void zigzag(int arr[], int n){

  bool flag=true;
  print(arr,n);

  for(int i = 0; i<n-1; i++){

    if(flag){
      if(arr[i]>arr[i+1])  swap(arr[i],arr[i+1]);
    }else{
      if(arr[i]<arr[i+1])  swap(arr[i],arr[i+1]);
    }
    flag = !flag;
    print(arr,n);
    }

}

int main(){
  int array[] = { 4,3,7,8,6,2,1};
  int n= sizeof(array)/sizeof(array[0]);

  zigzag(array,n);

  print(array,n);

  return 0;
}
