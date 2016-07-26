//Implementation of queue using linked list


#include <iostream>
#include <string>
#define MAX 100

using namespace std;



class Queue{

private:
  int arr[MAX];
  int front=-1, rear=-1;

public:

    void Enqueue(int x){

      if(rear > MAX){
        std::cout << "ERROR: Queue is FULL" << std::endl;
      }
      else{
        if(front ==-1 && rear == -1){
          front++;
          rear++;
          arr[rear]=x;
        }else{
          rear++;
          arr[rear]=x;
          }
        }
      return;
    }


  void Dequeue(){

    if(IsEmpty()){ std::cout << "Queue is Empty." << std::endl;}
    else if(front==rear){
      front=-1;
      rear=-1;
    }else{
        front++;
    }
    }

  bool IsEmpty(){
    if(front==-1 && rear==-1){
      return true;
    }
    return false;
    }

  int Front(){
    int start;
    start = arr[front];
    return start;
  }

  void print() {

    std::cout << "Queue is " << std::endl;
    for(int i=front;i<=rear;i++){
      std::cout << arr[i] << std::endl;
    }
  }

};


int main(){

  Queue q;

  for(int i=0;i<9;i++){
    q.Enqueue(i);
  }

  q.print();
  std::cout << "front is : "<< q.Front() << std::endl;

  for(int i=0;i<=10;i++){
    q.Dequeue();
  }

  q.print();
  std::cout << "front is : "<< q.Front() << std::endl;


  return 0;
}
