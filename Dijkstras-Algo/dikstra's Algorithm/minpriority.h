/**-----------------------------------------------------------------
*@File : minpriority.h
*@Name:Tejas Patil  @ChicoStateID: 006949762
*@Assignment No: 05 Part 1
*@Description:This file contains all function declerations for
            operations on Heap like Insert, Decrease key and extract
            minimum key.
*@Date: 30 April 2015
*-------------------------------------------------------------------*/

#ifndef MINPRIORITY_H_INCLUDED
#define MINPRIORITY_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MinPriorityQ{

public:
   MinPriorityQ();//constructor
   ~MinPriorityQ();//destructor
   void insert(string id, int key);//insert key and id
   void decreaseKey(string id , int newKey);//decrease key
   string extractMin();//extract minimum
   bool isMember(string id);//check for id
   void print();
   bool Empty();

private:
   void buildMinHeap();//build min heap
   void minHeapify(int i);//minheapify
   int parent(int i);//parent of i
   int left(int i);//Left child of i
   int right(int i);//right child of i

//class element
class Element{

public:
   string id;
   int Key;
};
vector <Element*> minHeap;
};
#endif // MINPRIORITY_H_INCLUDED
