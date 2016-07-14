/* This assignment originated at UC Riverside. The hash table size
 should be defined at compile time. Use -D HASH_TABLE_SIZE=X */

 /*----------------------------------------------------------------------
Name : TEJAS PATIL 006949762
Assignment No: 03
Date: .03/28/2015
Description: This file contains the function decleration for the functions
             decleared in hash.h . which are used to perform operation on
             Hash Table like insert,remove,delete and to calculate number
             of collision,avegerage length and loadfactor.
-----------------------------------------------------------------------*/


#ifndef __HASH_H
#define __HASH_H

#include <string>
#include <list>

using std::string;
using std::list;

class Hash {

public:
   Hash();                          // constructor
   void remove(string);             // remove key from hash table
   void print();                    // print the entire hash table
   void processFile(string);        // open file and add keys to hash table
   bool search(string);             // search for a key in the hash table
   void output(string);             // print entire hash table to a file
   void printStats();               // print statistics

private:
   // HASH_TABLE_SIZE should be defined using the -D option for g++
   list<string> hashTable [HASH_TABLE_SIZE];
   int collisions;                  // total number of collisions
   unsigned int longestList;        // longest list ever generated
   double avgLength;                // running average of average list length

   int hf(string);                  // the hash function

// put additional functions below as needed
// do not change anything above!
   double CurrentavgLength();       //calculates current average length
   unsigned int Longestlist();      //calculates longestList's length
   void Loadfactor();               //calculates loadfactor
   double loadfactor;               //loadfactor

};

#endif
