/*----------------------------------------------------------------------
Programming Assignment No: 1 (CSCI311 spring 15)
Name: Tejas Vamanrao Patil
Date : 6 Feb 2015

File Name: 
	doublylinklist.cpp Implementation of doublylinklist for music.
  
 Description:
    Implementation of a doublylinklist for music. A doubly linked 
    list is used to store the song names.

-----------------------------------------------------------------------*/


#include <iostream>
#include <string>
#include "doublylinkedlist.h"

using namespace std;




/*----------------------------------------------------------------------
Default Node constructor
-----------------------------------------------------------------------*/

DoublyLinkedList::Node::Node()
{	
	next=NULL;
	prev=NULL;
}
/*----------------------------------------------------------------------
Node parameteraised constructor defination
-----------------------------------------------------------------------*/

DoublyLinkedList::Node::Node(string& str)
{
	this->data = new string(str);
}

/*---------------------------------------------------------------------
Node Destructor 
-----------------------------------------------------------------------*/

DoublyLinkedList::Node::~Node()
{
	prev=NULL;
	next=NULL;
	data=NULL;
	
	delete next;
	delete prev;
	delete data;
}

/*----------------------------------------------------------------------
Doublylinklist constructor which sets null to head, tail and current
-----------------------------------------------------------------------*/

DoublyLinkedList::DoublyLinkedList()
{
	head = NULL;
	tail = NULL;
	current = NULL;
}

/*----------------------------------------------------------------------
Doublylink list destructor which frees momory after the end of code
-----------------------------------------------------------------------*/

DoublyLinkedList::~DoublyLinkedList()
{
	while(head != NULL)
      {
         current = head;
         head = head->next;
         delete current;
      }
      

}

/*----------------------------------------------------------------------
definatio of Emply()which return true if list is empty else it return
false
-----------------------------------------------------------------------*/

bool DoublyLinkedList::empty()
{
  if(head == NULL)
    return true;
  else
    return false;  
}

/*----------------------------------------------------------------------
Appende at the end of list
1.if list is empty then simply add the node
2.if list is not empty then find tail node and append song after it
-----------------------------------------------------------------------*/

void DoublyLinkedList::append(string& str)
{
     if (head==NULL)
    {
        
        head = new Node(str);
        head->next=NULL; 
        head->prev=NULL;
	current=head;
	tail=head;
	
     }     
 
   else 
	{
         
        Node *temp = head;
        while(temp->next !=NULL)
        temp = temp->next;
            
        temp->next = new Node(str);
        temp->next->next = NULL;
        temp->next->prev = temp;
         
	current=temp->next;
	tail=temp->next;
	

	}
	
}

/*----------------------------------------------------------------------
Insert the song before the current song
1.if list is empty the it add node as a head
2.current is head then it insert at begining of list
3.it current is not head menas it may be tail ir any other node
except head then it add node before current and reestablish propper
links with new node
-----------------------------------------------------------------------*/

void DoublyLinkedList::insertBefore(string& str)
{
   
     if (head==NULL)
    {
        
        head = new Node(str);
        head->next=NULL; 
        head->prev=NULL;  
	current=head;
	tail=head;                
    } 
	   
    else if(current == head)
	{
	Node *temp = new Node(str);
	temp->next=head;
	temp->prev=NULL;
	head->prev=temp;
	//temp=head;
	head=temp;
	current=temp;	
	}
	else
	{	
	Node *temp = new Node(str);
 
	temp->next=current, 
	temp->prev=current->prev;
	temp->prev->next = temp;
    	current->prev = temp;
    	current = temp;
	}		
}

/*----------------------------------------------------------------------
Insert Song into doublylinklist after the current Song
1.if list is empty the it add node as a tail
2.current is tail then it insert at the end of list
3.it current is not tail menas it may be head ir any other node
except head then it add node before current and reestablish propper
links with new node
-----------------------------------------------------------------------*/

void DoublyLinkedList::insertAfter(string& str)
{
    if (head==NULL)
	{
        head = new Node(str);
       // head->data = str;
        head->next=NULL; 
        head->prev=NULL;  
	current=head;
	tail=head;                
	} 
	else if(current == tail)
	{
    	Node *temp = new Node(str);
	temp->next = NULL;
 	temp->prev=current;
    	current->next = temp;
    	tail = temp;
    	current = temp;  
	}
 	 else
  	{
    	Node *temp = new Node(str);
	temp->next = current->next; 
	temp->prev = current;
    	temp->next->prev = temp;
    	current->next = temp;
    	current = temp;
  	}	
}

/*----------------------------------------------------------------------
it removes the song if present else ignore command
1.it will execute if list contains the node enterned by user else it 
exits loop
2.if list has only onle node then we have to delete it and make list
empty
3.if song present at head node and it has more than one element 
make next node of current as a head and delete present head
4.if song is present at tail than delete tail and assign null to previous
of tail
5.if cureent is not head neither tail than simple remove current and
restablish links and delete current and then reassign current 
-----------------------------------------------------------------------*/

void DoublyLinkedList::remove(string& str)
{
	if(find(str))
	{
	//Node *temp3=current;
	if(*head->data == str && head->next == NULL)  //single node
	{
	current = NULL;
      	head = NULL;
      	tail = NULL;
	delete head;
	}
	else if(*head->data == str && head->next != NULL) //first node
	{
	  Node *temp=head;
	  temp->next->prev=NULL;
 	  head = temp->next;
	  current=head;
	  delete temp;
	
	}

	else if(*tail->data==str)   //last tail node
	{
	Node *temp=tail;
	temp->prev->next=NULL;
	current=temp->prev;
	tail=current;	
	delete temp;	
	}

	else			
	{
	Node *temp = current;
	current->prev->next = current->next;
	current->next->prev = current->prev;
	current=current->next;
	delete temp;
	/*
	Node *temp=current;
	temp->prev->next = temp->next;
        current = temp->next;
        current->prev = temp->prev;
    	delete temp;
	*/	
      }
   }
}

/*----------------------------------------------------------------------
reset current to the head which means at the start of list
-----------------------------------------------------------------------*/

void DoublyLinkedList::begin()
{
	current = head;
}

/*----------------------------------------------------------------------
reset current to the tail which means at the end of list
-----------------------------------------------------------------------*/

void DoublyLinkedList::end()
{
	current = tail;
}


/*----------------------------------------------------------------------
It assigns the current song to the next song of current song
and ignore if list is empty. it returns true an false accordingly
-----------------------------------------------------------------------*/

bool DoublyLinkedList::next()
{
	while(head != NULL)
	{
	if(current->next != NULL)
	{
  	current = current->next;
	return true;
	}
	else
	    return false;
	}
	return false;
}

/*----------------------------------------------------------------------
It assigns the current song to the previos song of current song
and ignore if list is empty.it returns true an false accordingly
-----------------------------------------------------------------------*/

bool DoublyLinkedList::prev()
{
	//cout << "u r at prev";


	while(head != NULL)
	{
	if(current->prev != NULL)
	{
  	current = current->prev;
	return true;
	}
	else
	    return false;
	}
	return false;
}

/*----------------------------------------------------------------------
This finds the song entered by user id song is present it returns
true else it returns false.
and assign it as a current song if it is present in list 
-----------------------------------------------------------------------*/

bool DoublyLinkedList::find(string& str)
{
	
        if (head == NULL)
	{ 
	return false;
	}
	else 
         {
	Node *temp = head;
	while(temp!=NULL)
	{
	
		if (*temp->data == str)
		{
		current=temp;
		//cout << "song is present:" << *temp->data;
	   	return true;
		}
	else
		temp = temp->next;    
	}
	return false;
}
}

/*----------------------------------------------------------------------
Returns constant value i.e. data of the current node
-----------------------------------------------------------------------*/

const string& DoublyLinkedList::getData()
{
return *current->data;
}
