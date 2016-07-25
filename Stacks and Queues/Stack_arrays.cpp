/*
LIFO - Stack using Arrrays
*/

#include <iostream>
#define MAX_SIZE 101


using namespace std;


class stack{

private:
    int arr[MAX_SIZE];
    int top;

public:
    stack(){
      top=-1;
    }//constructor

    void push(int x){
      if(top == MAX_SIZE -1){
        std::cout << "Stack overflow" << std::endl;
        }
        else{
      top=top+1;
      arr[top]=x;
    }
  }

    int pop()
    {
      if(top == -1) {
      std::cout << "Error: Stack Underflow" << std::endl;
			return -1;
		}
		top--;
    return arr[top+1];
    }

    bool isempty(){
      if(top==-1) return true;
      return false;
    }


    void display(){
      std::cout << "Stack is: ";
      if(top==-1){
        std::cout << "EMPTY" << std::endl;
      }
      else {
          for (int i = 0; i <= top; i++) {
          std::cout << "\nelement at "<<i <<" :"<<arr[i] << std::endl;
          }
         }
        }

};


int main(){
  stack s;

  for(int i=0;i<20;i++){
    s.push(i);
  }
  s.display();


  return 0;

}
