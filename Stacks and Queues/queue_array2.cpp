//Implementation of queue using linked list
//efficient memory utilization
//REF: mycodeschool.com


#include <iostream>
#include <string>
#define MAX 10

using namespace std;



class Queue{

private:
  int arr[MAX];
  int front=-1, rear=-1;

public:

    void Enqueue(int x){

      if((rear+1)%MAX==front){
        std::cout << "ERROR: Queue is FULL" << std::endl;
      }
      else{
        if(front ==-1 && rear == -1){
          front=0;
          rear=0;
          arr[rear]=x;
        }else{
          rear=(rear+1)%MAX;
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
        front=(front+1)%MAX;
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
    if(front == -1)
		{
			cout<<"Error: cannot return front from empty queue\n";
			return -1;
		}else{

      start = arr[front];
      return start;
    }
  }

  void print() {

		// Finding number of elements in queue
		int count = (rear+MAX-front)%MAX + 1;
		cout<<"\nQueue       : ";
		for(int i = 0; i <count; i++)
		{
			int index = (front+i) % MAX; // Index of element while travesing circularly from front
			cout<<arr[index]<<" ";
		}
		cout<<"\n\n";
  }

};


int main(){

  Queue q;

  for(int i=0;i<8;i++){
    q.Enqueue(i);
  }

  q.print();
  std::cout << "front is : "<< q.Front() << std::endl;

  for(int i=0;i<=3;i++){
   q.Dequeue();
  }

  for(int i=0;i<5;i++){
    q.Enqueue(i);
  }


  q.print();
  std::cout << "front is : "<< q.Front() << std::endl;


  return 0;
}
