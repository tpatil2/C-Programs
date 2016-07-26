
/*
Problem:  check for palindrom singly linked list
*/


#include <iostream>
#include <string>
#include <stack>

using namespace std;

class node{
public:
  char data;
  node* next;
};


node* head=NULL;
node* tail=NULL;

bool check_palindrome(){
  node* slowptr;
  node* fastptr;
  slowptr=fastptr=head;

  std::stack<char> mystack;

  while(fastptr!=NULL && fastptr->next != NULL){
        mystack.push(slowptr->data);
        fastptr=fastptr->next->next;
        slowptr=slowptr->next;
  }

  //for odd length need to move next to midpoint
  if(fastptr != NULL) slowptr=slowptr->next;
  //pop elements and check with remaining list
  while(slowptr != NULL){
    if(slowptr->data != mystack.top()) return false;
    mystack.pop();
    slowptr=slowptr->next;
  }

return true;
}

void Ispalindrome() {

  if(check_palindrome()){
    std::cout << "Linked list is palindrome" << std::endl;
  }
  else{
    std::cout << "Linked list is not palindrome" << std::endl;
  }
  std::cout << "---------------------" << std::endl;

}

void print(){

  node * temp=new node;
  temp=head;
  while(temp->next != NULL){
    std::cout << temp->data<<"  ";
    temp=temp->next;
  }

  std::cout << temp->data<<std::endl;

}

int main(){
  node* curr=new node;
  string str="abcdedcba";
  for(int i=0;i<str.length();i++){
    if(head==NULL){
      curr->data=str[i];
      curr->next=NULL;
      head=curr;
      print();
      Ispalindrome();

    }
    else{
      node * temp=new node;
      temp->data=str[i];
      curr->next=temp;
      temp->next=NULL;
      tail=curr=temp;
      print();
      Ispalindrome();

    }
  }

}
