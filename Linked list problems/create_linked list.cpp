/*
creat singly linked list
*/


#include <iostream>
#include <string>


class node{

public:

  int data;
  node* next;

};


int main(){

  node* head;
  node* temp;
  node* curr;
  int size,ipt;

  std::cout << "Enter size of linked list" << std::endl;
  std::cin >> size;

  curr=new node;
  std::cout << "Enter the First element" << std::endl;
  std::cin >> ipt;
  curr->data=ipt;
  head=curr;
  temp=curr;


  for(int i=1;i<size;i++){
    curr=new node;
    std::cout << "Enter the next element" << std::endl;
    std::cin >> ipt;
    curr->data=ipt;
    temp->next=curr;
    temp=temp->next;
  }

  curr->next=NULL;

  std::cout << "Your linked list is : " << std::endl;

  node* tracker;
  tracker=head;


      while(tracker != NULL){
        std::cout << " "<< tracker->data <<"->";
        tracker=tracker->next;
      }
      std::cout << " " << std::endl;



      std::cout << "curr-Data 1  :"<<curr->data << std::endl;

      curr=head;

      std::cout << "curr-Data 2  :"<<curr->data << std::endl;



      for(int i=0 ; i<3;i++){

          curr=curr->next;

      }

      std::cout << "curr-Data 4  :"<<curr->data << std::endl;


      std::cout << "Deleting Node " << std::endl;

      node* extra;

      extra=curr;

      extra->data=curr->next->data;
      extra->next=curr->next->next;

//delete curr;


      tracker=head;


          while(tracker != NULL){
            std::cout << " "<< tracker->data <<"->";
            tracker=tracker->next;
          }
          std::cout << " " << std::endl;

}
