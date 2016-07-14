/*----------------------------------------------------------------------
Programming Assignment No: 1 (CSCI311 spring 15)
Name: Tejas Vamanrao Patil
Date : 6 Feb 2015
file Nmae: playlist.h   Declaration of a Playlist for music.
 
Description:
     Implementation of Playlist for music, where a doubly linked list is
     used to store the song names.

-----------------------------------------------------------------------*/


#ifndef CSCI_311_PLAYLIST_H
#define CSCI_311_PLAYLIST_H

#include "doublylinkedlist.h"
using std::string;


/*----------------------------------------------------------------------
Description:
Decleration of class playlist, mainloop and process commands
-----------------------------------------------------------------------*/

class Playlist {
public:
   void mainLoop();                    // process commands until done
private:
   
   DoublyLinkedList dll;               // playlist stored in doubly linked list
   
   void processCommand();              // read and process one playlist command

	
};

#endif // CSCI_311_PLAYLIST_H
