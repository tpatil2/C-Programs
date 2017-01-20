#include <iostream>

using namespace std;



int main()
{

  int rows =10;
  int columns =10;
  double **darray = new double*[rows];

  for(int r=0;r<rows;r++){
    darray[r] = new double*[columns];
  }
}
