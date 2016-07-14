/**-----------------------------------------------------------------
*@File : rbapp.cpp
*@Name:Tejas Patil  @ChicoStateID: 006949762
*@Assignment No: 04
*@Description:This file takes input and pass it to functions in
               rbapp.cpp to make operation on Red Black Tree
*@Date: 18 April 2015
*-------------------------------------------------------------------*/


#include <iostream>
#include <string>
#include "rbapp.h"

using namespace std;

/*----------------------------------------------------------------------
*Description: RBapp constructor
*INPUT: void
*OUTPUT: void
*----------------------------------------------------------------------*/

RBapp::RBapp()
{
   done=false;
}

/*-----------------------------------------------------------------------
*Description: Main function start of the program which calls mainloop()
*INPUT: void
*OUTPUT: void
*----------------------------------------------------------------------*/

int main()
{
   RBapp myRBTapp;
   myRBTapp.mainLoop();
   return 0;
}

/*-----------------------------------------------------------------------
*Description: This function checks for n=end of file or quit command
*INPUT: void
*OUTPUT:void
*----------------------------------------------------------------------*/

void RBapp::mainLoop()
{
   while(!cin.eof() && !done)
   processCommand();
}


/*-----------------------------------------------------------------------
*Description: This function accepts inpt and make strings operations
               and performs respective task
*INPUT: void
*OUTPUT: void
*---------------------------------------------------------------------*/
void RBapp::processCommand()
{
   string key_data,key,command,input;
   getline(cin, input);
   command = input.substr(0,input.find(" "));
   if(command == "insert")
   {
      input.erase(0, input.find(" ") + 1);
      key_data=input.substr(0, input.find("\n"));
      processInsert(key_data);
   }
   else if(command == "print")
   {
         processPrint();
   }
   else if(command == "find")
   {
      input.erase(0,input.find(" ") + 1);
      key=input.substr(0, input.find("\n"));
      processFind(key);
   }
   else if(command == "delete")
   {
      input.erase(0,input.find(" ") + 1);
      key_data=input.substr(0, input.find("\n"));
      processDelete(key_data);
   }
   else if(command == "quit")
   {
      processQuit();
   }
}

/*-----------------------------------------------------------------------
*Description: this function accepts key and data and pass it to
               rbInsert() function
*INPUT: void
*OUTPUT: void
*---------------------------------------------------------------------*/

void RBapp::processInsert(string& key_data)
{
   string data,key;
   key=key_data.substr(0, key_data.find(" "));
   key_data.erase(0, key_data.find(" ") + 1);
   data=key_data.substr(0, key_data.find("\n"));
   myRBT.rbInsert(key, data);
}

/*-----------------------------------------------------------------------
*Description:This function calls to rbprinttree()

*INPUT: void
*OUTPUT: void
*----------------------------------------------------------------------*/

void RBapp::processPrint()
{
   myRBT.rbPrintTree();
}

/*-----------------------------------------------------------------------
*Description: this function pass key to rbFind() function
*INPUT:void
*OUTPUT:void
*----------------------------------------------------------------------*/

void RBapp::processFind(string& key)
{
   vector<const string*> printvector = myRBT.rbFind(key);
   for (unsigned int i=0; i < printvector.size(); i++)
   {
      cout << key <<" "<< *printvector[i] << endl;
   }
}

/*-----------------------------------------------------------------------
*Description: this function passes key and data to rbdelete()
*INPUT:void
*OUTPUT:void
*----------------------------------------------------------------------*/

void RBapp::processDelete(string& key_data)
{
   string key,data;
   key=key_data.substr(0, key_data.find(" "));
   key_data.erase(0, key_data.find(" ") + 1);
   data=key_data.substr(0, key_data.find("\n"));
   myRBT.rbDelete(key, data);
}

/*-----------------------------------------------------------------------
*Description: this function quits execution
*INPUT:void
*OUTPUT:void
*----------------------------------------------------------------------*/

void RBapp::processQuit()
{
	done=true;
}
