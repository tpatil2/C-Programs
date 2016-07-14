/*----------------------------------------------------------------------
Programming Assignment No: 1 (CSCI311 spring 15)
Name: Tejas Vamanrao Patil
Date : 6 Feb 2015
  
File Name: playlist.cpp   Implementation of a Playlist for music.
  
 Description:
    Implementation of a Playlist for music. A doubly linked list is
    used to store the song names.

-----------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <string.h>
#include "playlist.h"
//#include "doublylinkedlist.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;


string U_str,temp,input;
/*----------------------------------------------------------------------
Description: Process a playlist command.Gets an entire line from 
std::cin, extracts the first word as the command,and calls the
appropriate processing function. Invalid commands are ignored.
-----------------------------------------------------------------------*/

void Playlist::processCommand() 
{
 
  //string str,input;
  getline(cin, U_str);
	int p,q;
  
 
 input = U_str.substr(0,U_str.find(' '));
  p = input.length();
  q = U_str.length();

  if (p<q)
	{
	temp = U_str.substr(p+1);
	}
	else temp="";
 
//temp = U_str.substr(U_str.find(' ')+1,U_str.find('\n'));
	            
 	if (input.compare("appendSong") == 0)  
		{if(temp!="")dll.append(temp);}
	else if (input.compare("insertBefore") == 0) 
		{if(temp!="")dll.insertBefore(temp);}
	else if (input.compare("insertAfter") == 0)
		{if(temp!="")dll.insertAfter(temp);}
	else if (input.compare("gotoFirstSong") == 0)
		dll.begin();
	else if (input.compare("gotoLastSong") == 0)
		dll.end();
     //playcurrent prints current song ans ignare if list is empty
	else if (input.compare("playCurrent") == 0)
		{cout << endl << "playing current: ";
   		if (!dll.empty()) cout << dll.getData() << endl;
		}
	else if (input.compare("removeSong")  == 0)
		{if(temp!="")dll.remove(temp);}
	else if (input.compare("gotoSong") == 0)
		{if(temp!="")dll.find(temp);}
	else if (input.compare("nextSong") == 0) 
		dll.next();
	else if (input.compare("prevSong") == 0) 
		dll.prev();
	else if (input.compare("playForward") == 0)  
		{ cout << endl << "playing forward: " << endl;
  			 if (!dll.empty())
      			do {cout << dll.getData() << endl;}
      			while (dll.next());}
	else if (input.compare("playReverse") == 0)  
		{cout << endl << "playing reverse: " << endl;
   		if (!dll.empty())
      		do {cout << dll.getData() << endl;}
      		while (dll.prev());}
  }



//The Playlist main loop will process command lines until eof.

/*----------------------------------------------------------------------
Description:Mainloop accpets command form console
-----------------------------------------------------------------------*/
   
void Playlist::mainLoop() {
   while (!cin.eof()) processCommand();         // process all commands
}


 // The main entry point for the program.
 
/*----------------------------------------------------------------------
Description: Main function gives call to mainloop and initiate 
	execution
-----------------------------------------------------------------------*/

int main()
{
   Playlist myPlaylist;
   myPlaylist.mainLoop();
   return 0;
}
   
/*-------------------End Of Playlist.cpp----------------------
-----------------------------------------------------------------------*/
