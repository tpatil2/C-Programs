#include <iostream>
#include <stack>

using namespace std;

int main(){

  //int a[]={1,1,2,4,3,3,4,4,4,3,3,3,4,0,5,3};
  //int a[]={1,1,1,1,1,1,1,2,2,2,1,1,1,1,1,1,1,2,4,3,3,4,4,4,3,3,3,4,0,5,3};
  //int a[]={1,2,3,4,5,6,7,8};
  //int  a[] = {};
  int a[]={5,2,2,4,2,2,3,1};

  stack<int> mystack;
  int size=sizeof(a)/sizeof(int);
  std::cout << "size is "<<size << std::endl;


  int j=0;
  int k=1;
  int len=2;
  bool flag = false;

  for(int i=2;i<size;i++){

      while(a[k]==a[j]){
        len++;
        i++;
        j++;
        k++;
        flag = true;
      }
      while(a[i] == a[k] || a[i]==a[j]){
      len++;
      i++;
      }

      mystack.push(len);
      len = 1;
      i--;
      j=i;
      k=j+1;
  }


  int largest=0;
  while(!mystack.empty()){

    if(largest < mystack.top()) largest=mystack.top();
    std::cout << "len is "<<mystack.top() << std::endl;
    mystack.pop();

  }

  if(largest==2 && flag == false) largest = 1;

  std::cout << "largest is "<< largest << std::endl;

  return 0;

}
