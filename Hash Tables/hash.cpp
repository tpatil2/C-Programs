/*----------------------------------------------------------------------
Name : TEJAS PATIL 006949762
Assignment No: 03
Date: .03/28/2015
Description: This file contains the function defination for the functions
             decleared in hash.h . which are used to perform operation on
             Hash Table like insert,remove,delete and to calculate number
             of collision,avegerage length and loadfactor.
------------------------------------------------------------------------*/

#include<stdio.h>
#include<iostream>
#include<iomanip>
#include <string.h>
#include<string>
#include<fstream>
#include"hash.h"

using namespace std;
list < string > ::iterator it;


/*----------------------------------------------------------------------
Description: This is the constructor which initialize thr values for
collision, longestList and avgList;
------------------------------------------------------------------------*/
Hash::Hash()
{
   collisions = 0;
   longestList = 0;
   avgLength = 0;

}
/*----------------------------------------------------------------------
Description: This function removes the string from Hash_Table with
              respect to hash key from the specific location
Input: ip_str ths is the srting input which has to be removed
Output: void
------------------------------------------------------------------------*/
void Hash::remove(string ip_str) // remove hashvalue from hash table
{
   int key;
   key = hf(ip_str);

   for (it = hashTable[key].begin(); it != hashTable[key].end(); ++it)
   {
      if (ip_str == *it)
      {   //the line below erases the string
         hashTable[key].erase(it);
         //Here we calculate updated average length
         avgLength = (CurrentavgLength() + avgLength) / 2.0;
         break;
      }
   }
}

/*-----------------------------------------------------------------------
Description: This function displays Hash table
Input: void
Output: void
-------------------------------------------------------------------------*/
void Hash::print()// print the entire hash table
{
   int i;

   for (i = 0; i < HASH_TABLE_SIZE; i++)
   {
      cout << i << ":" << "\t";
      for (it = hashTable[i].begin(); it != hashTable[i].end(); it++)
      {
         cout << *it << ", ";
      }
         cout << endl;
   }
}

/*-------------------------------------------------------------------------
Description: This function accept the string from input file and
             fix it in hash table
Input: ip_str =this is the srting input which has to be added in hash table
Output:void
--------------------------------------------------------------------------*/
void Hash::processFile(string ip_str)
{
   int key;
   ifstream fptr;
   fptr.open(ip_str);
   string str;
   collisions = 0;
   if (fptr.is_open())
   {
      while (getline(fptr, str))
      {
         key = hf(str);
         if(!hashTable[key].empty())
         collisions++;//counts collisions;
         hashTable[key].push_back(str);
         //returns longest list
         Longestlist();
         //Here we calculate updated average length for every insert
         avgLength = (CurrentavgLength() + avgLength) / 2.0;
      }
   }
   fptr.close();
}

/*---------------------------------------------------------------------
Description: This function search the input strings
Input: ip_str the String to be serached.
Output: it returns true or false. (of type bool)
-----------------------------------------------------------------------*/
bool Hash::search(string ip_str)
// search for a hashvalue in the hash table
{
   int key;
   key = hf(ip_str);

   for (it = hashTable[key].begin(); it != hashTable[key].end(); it++)
   {
      // checks whether it is present or not
      if (ip_str == *it)
		{
         return true;
      }
   }
   return false;
}

/*-----------------------------------------------------------------------
Description: This function passes the output of the Hash_Table
             which is updated after all operation on hash table
             (like remove, search) to "hash.out"
Input: void
Output: void
------------------------------------------------------------------------*/

void Hash::output(string)
{
   int i;
	{
      ofstream op_str;
      op_str.open("hash.out");
      // print entire hash table to a file hash.out
      {
         list < string > ::iterator it;
         for (i = 0; i < HASH_TABLE_SIZE; i++)
         {
            op_str << i << ":" << "\t";
            for(it=hashTable[i].begin();it!=hashTable[i].end();it++)
            {
               op_str << *it << ", ";
            }
               op_str << endl;
         }
      }
      op_str.close();
   }
}

/*----------------------------------------------------------------------
Description: This function calculates the average value.
Input: void
Output:it returns avg of type double
-------------------------------------------------------------------------*/
double Hash::CurrentavgLength()
{
   double cur_avg = 0, len = 0 ,curr=0;
   int i = 0;
   double j = 0;

   for(i=0; i < HASH_TABLE_SIZE;i++)
   {
      curr = (hashTable[i].size());
      len = len + curr;
      //calculates total numbers of elements in hash Table
      if(!hashTable[i].empty())
      {
         j++;
      }//calculates non empty Lists
   }
   cur_avg = (len/(j));
   return cur_avg;
}

/*----------------------------------------------------------------------
Description: This function calculates the longestList length
Input: void
Output:it returns longestList length
------------------------------------------------------------------------*/
unsigned int Hash::Longestlist()
{
   int l1 = 0, l2 = 0;
   list < string > ::iterator it;
   for (int i = 0; i < HASH_TABLE_SIZE; i++)
   {
      for (it = hashTable[i].begin(); it != hashTable[i].end(); it++)
      {
         //increments the l2 for every element present in hashtable
         l2++;
      }
      if (l1 <= l2)
      {
         //checks current lenght with previous length
         l1 = l2;
         longestList = l1;
         //exchane if current lenght is more than previous length
      }
      l2 = 0;
   }
   return longestList;
}


/*-----------------------------------------------------------------------
Description: This function calculates the load factor
Input: void
Output: void
------------------------------------------------------------------------*/
void Hash::Loadfactor()
{
   double m=0;
   list < string > ::iterator it;
   for (int i = 0; i < HASH_TABLE_SIZE; i++)
   {
      for (it = hashTable[i].begin(); it != hashTable[i].end(); it++)
      {
         m++;
      }
   }
   //loadfactor=total number of elemrnts/Hash_table_size
   loadfactor = (m/HASH_TABLE_SIZE);
}

/*-----------------------------------------------------------------------
Description: this functions prints values of number of collisions,
             longest chain and average length
Input: void
Output:void
-----------------------------------------------------------------------*/
void Hash::printStats()
{
   Loadfactor();
   cout << "Total Collisions = " << collisions << endl;
   cout << "Longest List Ever = " << longestList << endl;
   cout << "Average List Length Over Time = " << avgLength << endl;
   cout << "Load Factor = "<< loadfactor << endl;
}// print statistics

/*---------------------------------End---------------------------------*/
