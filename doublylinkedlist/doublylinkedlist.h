/*----------------------------------------------------------------------
Programming Assignment No: 1 (CSCI311 spring 15)
Name: Tejas Vamanrao Patil
Date : 6 Feb 2015

File Name: playlist.h Implementation of a Playlist for music.
Description:
    Implementation of a Playlist for music. A doubly linked list is
    used to store the song names.
-----------------------------------------------------------------------*/

#include <iostream>
#include <string>


using namespace std;


/*----------------------------------------------------------------------
Description: Decleration of class DoublyLinkedList and Node
which act as a decleration for doublylinked list
-----------------------------------------------------------------------*/
class DoublyLinkedList

{
 private:


//class Node decleration and it constructor and Destructor
  class Node
  {
     public:

	Node();
	Node(string& str);
	~Node();  //Node dectructor


	//Node pointers
  string* data;
	Node* next;
	Node* prev;
   };

	Node* head;
	Node* tail;
	Node* current;



 public:
	//Doublylinkedlist constructor and destructor decleration
 	DoublyLinkedList();
	~DoublyLinkedList();
    	bool empty();
    	void append(string& str);
    	void insertBefore(string& str);
    	void insertAfter(string& str);
    	void remove(string& str);
    	void begin();
    	void end();
    	bool next();
    	bool prev();
    	bool find(string& str);
    	const string& getData();

};



/*-------------------------------EOF-----------------------------------*/
