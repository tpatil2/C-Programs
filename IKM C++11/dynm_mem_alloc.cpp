#include <iostream>
using namespace std;

int main(){
  int n;

  cout << "Enter value of n" << '\n';
  cin >> n;

  int* p = (int*)malloc(n*sizeof(int));

  for(int k=0;k<n;k++){
      p[k]=k;
  }

  free(p);

  for(int k=0;k<n;k++){
    std::cout << *(p+k) << '\n';
  }

  return 0;
}
