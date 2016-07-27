
/*
Problem: You have two numbers represented by a linked list, where each node
contains a single digit. The digits are stored in reverse order, such
that the Ts digit is at the head of the list. Write a function that
adds the two numbers and returns the sum as a linked list.
EXAMPLE
Input: (7-> 1 -> 6) + (5 -> 9 -> 2).That is, 617 + 295.
Output: 2 -> 1 -> 9.That is, 912
*/


#include <iostream>
#include <string>
#include <queue>

using namespace std;

class node{
public:
  int data;
  node* next;
};


node* head1=NULL;
node* tail1=NULL;
node* head2=NULL;
node* tail2=NULL;
std::queue<int> myqueue1;
std::queue<int> myqueue2;
std::queue<int> myqueue3;




void add_list(){

  int carry=0;

   while (!myqueue1.empty() && !myqueue2.empty() ){

     int sum=0,unit=0;

      sum=myqueue1.front()+myqueue2.front()+carry;
      carry=sum/10;
      unit=sum%10;
      myqueue1.pop();
      myqueue2.pop();
      myqueue3.push(unit);
   }

   while (!myqueue3.empty()) {

     std::cout << "myqueue3 is : "<< myqueue3.front() << std::endl;
     myqueue3.pop();

   }




  return;

}




void pass_list(){



  node * temp=new node;

  temp=head1;

    while(temp->next!=NULL){
      myqueue1.push(temp->data);
    //  std::cout << "myqueue.front() is now " << myqueue1.front() << '\n';
      temp=temp->next;
    }

    myqueue1.push(temp->data);
  //  std::cout << "myqueue.front() is now " << myqueue1.front() << '\n';

    temp=head2;
    while(temp->next!=NULL){
      myqueue2.push(temp->data);
    //  std::cout << "myqueue2.front() is now " << myqueue2.front() << '\n';
      temp=temp->next;

    }

    myqueue2.push(temp->data);
  //  std::cout << "myqueue2.front() is now " << myqueue2.front() << '\n';

  return;
}






void print(){

  node * temp=new node;

  std::cout << "List first " << std::endl;
  temp=head1;
  while(temp->next != NULL){
    std::cout << temp->data<<"  ";
    temp=temp->next;
  }
  std::cout << temp->data<<std::endl;

  std::cout << "List second" << std::endl;
  temp=head2;
  while(temp->next != NULL){
    std::cout << temp->data<<"  ";
    temp=temp->next;
  }
  std::cout << temp->data<<std::endl;

}

int main(){
  node* curr1=new node;
  node* curr2=new node;

  int str1[]={7,1,6};
  int str2[]={5,9,2};


  for(int i=0;i<3;i++){

    if(head1==NULL){
      curr1->data=str1[i];
      curr1->next=NULL;
      head1=curr1;

    }
    else{
      node * temp=new node;
      temp->data=str1[i];
      curr1->next=temp;
      temp->next=NULL;
      tail1=curr1=temp;

    }
  }



  for(int i=0;i<3;i++){
    if(head2==NULL){
      curr2->data=str2[i];
      curr2->next=NULL;
      head2=curr2;

    }
    else{
      node * temp=new node;
      temp->data=str2[i];
      curr2->next=temp;
      temp->next=NULL;
      tail2=curr2=temp;

    }
  }

  print();
  pass_list();
  add_list();


}
