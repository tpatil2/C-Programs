/*
Stack using singly linked list
*/


#include <iostream>
#include <string>

using namespace std;

class node{

private:
  int data;
  node* next;
  node* top;

public:

  node(){
         top=NULL;
         next=NULL;
       }

  void push(int x){
    node* temp = new node;
    temp->data=x;
    temp->next=top;
    top=temp;
    std::cout << "Pushed" << std::endl;
  }

  void pop(){
    node* temp = new node;
    temp=top;
    top=top->next;
    temp->next=NULL;
    delete temp;
    std::cout << "popped" << std::endl;
  }

  void print(){
    node* temp = new node;
    std::cout << "Stack is :" << std::endl;
    temp=top;
    while(temp!=NULL){
      std::cout << temp->data << std::endl;
      temp=temp->next;
    }
    delete temp;
  }

};

int main(){

  node stack;

  for(int i=9;i>1;i--){
    stack.push(i);
  }
  stack.pop();
  stack.pop();
  stack.pop();
  stack.pop();

  stack.print();


  return 0;
}
