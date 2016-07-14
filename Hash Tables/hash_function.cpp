/* This assignment originated at UC Riverside.*/
/*
 Name: Tejas Patil 006949762
 Assignment No: 03
 Description: this file contains hash function
*/

/*-----------------------------------------------------------------

This hash function is easy to compute and it distribute all the
elements evenly, I have used prime numbers to distribute elements
evenly in to the hash table,it gives lower load factor and reduces
collision.As our input is string so, hash function operates on its
ASCII values to generate hash key.the range of ASCII value is 0-127
This Hash function includes all the characters in to the string to
calculate hash key and produce hash key with respect to inout
string. I have selected every character in string using for loop
and multiples it with 27 and all sum together and divieded by hash
table size.

Refered from - LINK: https://www.youtube.com/watch?v=4ZJQ6ehmAsg
-------------------------------------------------------------------*/

#include <string>
#include "hash.h"

using std::string;



int Hash::hf ( string ins ) {

   //return ( (int) ins[0] ) % HASH_TABLE_SIZE;

   int i;
   int total=0;
   int l;
   l=ins.length();
   //loop iterates and coever all char in string
   for (i = 0;i < l; i++)
   {
      total = total + ins[l-i]*(27^i);
   }
   return (total % HASH_TABLE_SIZE);
}

