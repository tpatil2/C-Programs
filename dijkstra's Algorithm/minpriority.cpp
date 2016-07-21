/**-----------------------------------------------------------------
*@File : minpriority.cpp
*@Name:Tejas Patil  @ChicoStateID: 006949762
*@Assignment No: 05 Part 1
*@Description:This file contains all function defi9nations for
            operations on Heap like Insert, Decrease and extract minimum.
*@Date: 30 April 2015
*-------------------------------------------------------------------*/


#include <string>
#include <iostream>
#include "minpriority.h"

/**-------------------------------------------------------------------
*Description: This is destructor of MinpriorityQ,
*INPUT: void
*OUTPUT: void
*-------------------------------------------------------------------*/
MinPriorityQ::MinPriorityQ(){
}

/**---------------------------------------------------------------------
*Description: his is constructor of MinpriorityQ,frees memory
*INPUT: void
*OUTPUT: void
*---------------------------------------------------------------------*/
MinPriorityQ::~MinPriorityQ(){
/*vector<Element *>::iterator it;

for(it=minHeap.begin();it!=minHeap.end();it++){
delete *it;
minHeap.erase(minHeap.begin(),minHeap.end());
}*/
}

/**---------------------------------------------------------------------
*Description: This is insert function which inserts key and id to the
               heap
*INPUT: void
*OUTPUT: void
*---------------------------------------------------------------------*/


void MinPriorityQ::insert(string id, int key){

   Element *e1 = new Element();
   e1->id = id;
   e1->Key= key;

   if(key == 0)
   {
      minHeap.insert(minHeap.begin(),e1);
        //minHeap.push_front(e1);
   }
   else
      {
         minHeap.push_back(e1);
         //minHeap.insert(minHeap.end(),e1);
         decreaseKey(id, key);
      }
   buildMinHeap();

}
/**---------------------------------------------------------------------
*Description: This is decreasekey function which decrease the key
               corresponding to the id of newkey
*INPUT: void
*OUTPUT: void
*---------------------------------------------------------------------*/

void MinPriorityQ::decreaseKey(string id , int newKey){
int i,p;
p= minHeap.size();

   for( i=0; i < p;i++)
   {
      if(minHeap[i]->id == id)
      {
         if(newKey >= minHeap[i]->Key)
      {
        // cout<< "new key is greater or equal than current key"<< endl;
      }
      else
      {
         minHeap[i]->Key =newKey;
         while(i > 0 && minHeap[parent(i)]->Key > minHeap[i]->Key)
         {
         swap(minHeap[i],minHeap[parent(i)]);
         i=parent(i);
         }
      }
      break;
   }
   }
}
/**---------------------------------------------------------------------
*Description: This is function returns  minimum value from heap
*INPUT: void
*OUTPUT: return string
*---------------------------------------------------------------------*/

string MinPriorityQ::extractMin(){
int p;
p= minHeap.size();


   if(p!=0)
      {
         string mini = minHeap[0]->id;
         minHeap.erase(minHeap.begin());
         //minHeap.resize(minHeap.size()-1);
         minHeapify(0);
         return mini;

      }
      else
      {
         cout<<"empty";
      }
    return "";
}

/**---------------------------------------------------------------------
*Description: This function checks for id present or not
*OUTPUT: bool return value
*input: void
*---------------------------------------------------------------------*/
bool MinPriorityQ::isMember(string ){
return false;
}


/**---------------------------------------------------------------------
*Description: This function construct min heap
*INPUT: void
*OUTPUT: void
*---------------------------------------------------------------------*/
void MinPriorityQ::buildMinHeap(){
int p,i;
p= minHeap.size()-1;

   for(i=p/2 ; i >= 0 ; i-- )
   {
      minHeapify(i);
   }

}


/**---------------------------------------------------------------------
*Description: This is print function min heapify to heap by accepting
               the index
*INPUT: void
*OUTPUT: void
*---------------------------------------------------------------------*/
void MinPriorityQ::minHeapify(int i){

unsigned int l,r,p;
int smallest;
p= minHeap.size();

l = left(i);
r = right(i);

   if(l<p && minHeap[l]->Key < minHeap[i]->Key)
   {
      smallest = l;
   }
   else
   {
      smallest = i;
   }

   if(r<p &&  minHeap[r]->Key < minHeap[smallest]->Key )
   {
      smallest=r;
   }
   if(smallest != i)
   {
      swap(minHeap[i],minHeap[smallest]);
      minHeapify(smallest);
   }
}


/**---------------------------------------------------------------------
*Description: This is function returns parent by accepting index
*INPUT: void
*OUTPUT: int
*---------------------------------------------------------------------*/
int MinPriorityQ::parent(int i){

return ((i-1)/2);

}

/**---------------------------------------------------------------------
*Description: This is function returns left child by accepting index
*INPUT: void
*OUTPUT: int
*---------------------------------------------------------------------*/

int MinPriorityQ::left(int i){

return (2*i)+1;

}


/**---------------------------------------------------------------------
*Description: This is function returns right child by accepting index
*INPUT: void
*OUTPUT: void
*---------------------------------------------------------------------*/

int MinPriorityQ::right(int i){

return (2*i)+2;

}

/**-------------------------------------------------------------------
*Description: print minpriority queue
*INPUT: void
*OUTPUT: void
*-------------------------------------------------------------------*/
void MinPriorityQ::print(){

int q=minHeap.size();

   for(int i= 0;i<q;i++)
    {

    cout<<minHeap[i]->id<<"-----"<< minHeap[i]->Key<<endl;
    }


}
/**-------------------------------------------------------------------
*Description: check wheather queue is empty or not
*INPUT: void
*OUTPUT: bool
*-------------------------------------------------------------------*/

bool MinPriorityQ::Empty()
{

   if(minHeap.empty())
   return true;

   else

   return false;

}
