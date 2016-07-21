/*
Write an algorithm such that if an element in an MxN matrix is 0,
its entire row and column are set to 0.*/

#include <iostream>
#include <string>


using namespace std;


void display(int buffer[4][4]){

  for(int i=0;i<4;i++){

    for(int j=0;j<4;j++){
      cout<<" "<<"["<<buffer[i][j]<<"]";
    }
    std::cout << "\n";
  }
  std::cout << "\n";

}



int main(){

  int arr[4][4]={{00,01,02,03},
                 {10,11,0,13},
                 {20,21,22,23},
                 {0,31,32,33}};


  bool rows[4]={false};
  bool cols[4]={false};

  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      if(arr[i][j]==0){
        rows[i]=true;
        cols[j]=true; }
    }
  }


    for(int i=0;i<4;i++){
      for(int j=0;j<4;j++){
        if(rows[i]==true || cols[j]==true){
            arr[i][j]=0;  }
      }
    }

    display(arr);

  return 0;

}
