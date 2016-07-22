/*
create Doubly linked list
*/


#include <iostream>
#include <string>


struct node{

  int data;
  node* next;
  node* prev;

};


int main(){

  node* head;
  node* temp;
  node* curr;
  node* tail;

  int size,ipt;

  std::cout << "Enter size of linked list" << std::endl;
  std::cin >> size;

  curr=new node;
  std::cout << "Enter the First element" << std::endl;
  std::cin >> ipt;
  curr->data=ipt;
  head=curr;
  head->prev=NULL;
  temp=curr;


  for(int i=1;i<size;i++){
    curr=new node;
    std::cout << "Enter the next element" << std::endl;
    std::cin >> ipt;
    curr->data=ipt;
    temp->next=curr;
    curr->prev=temp;
    temp=temp->next;
  }

  curr->next=NULL;
  tail=curr;
  std::cout << "Your linked list is : " << std::endl;

  node* tracker;
  tracker=head;


      while(tracker != NULL){
        std::cout << " "<< tracker->data <<"->";
        tracker=tracker->next;
      }
      std::cout << " " << std::endl;

      std::cout << "Your reverse linked list is : " << std::endl;

      tracker=tail;
      while(tracker != NULL){
        std::cout << " "<< tracker->data <<"->";
        tracker=tracker->prev;
      }
      std::cout << " " << std::endl;




}
