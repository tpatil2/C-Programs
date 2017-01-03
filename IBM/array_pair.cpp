#include <iostream>

using namespace std;

void sum_up(int* arr, int sum){

  int size =14 ;//sizeof(arr)/sizeof(arr[0]);

  for(int i=0;i<size-1;i++){
    for(int j=i+1; j<size;j++ ){
      if((arr[i]+arr[j]) == sum){
        std::cout << arr[i]<<" "<<arr[j] << std::endl;
      }
    }
  }
}


int main(){

  int array[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
  sum_up(array,8);

  return 0;

}
