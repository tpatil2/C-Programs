/**-----------------------------------------------------------------------
 * Programming Assgnment: 2
 * @file CensusDataSorts.cpp   Sort functions for census population data.
 *
 * @brief
 *    Implements several different types of sorts. Data can be sorted
 * by population or by name of town. This file contains all of the sorting
 * functions and their helpers.
 *
 * @author Judy Challinger
 * @date 2/22/13
 * @edited by Tejas Patil ,CHICO-STATE ID-006949762
 * @date 3/5/2015
 -----------------------------------------------------------------------*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "CensusData.h"
#include <limits.h>
#include <math.h>
#include <random>
#include <ctime>

using namespace std;

/**----------------------------------------------------------------------
 *Description: In insertionSort() function it operates on given input
 *             It checks elements in input file with the key and inseet
 *             respective element in sorted sequence
 *Input: int
 *Output: void
 *-----------------------------------------------------------------------*/

void CensusData::insertionSort(int type)
{
   Record* key;
   int i,j;
   if(type==0)
   {
      for(j=1;j<getSize();j++)
      {
         key=data[j];
         i=j-1;
         //Inserts data[j] into sorted sequence data[1....j-1]

      while(i>=0 && data[i]->population > key->population)
      {
         data[i+1]=data[i];
         i=i-1;

      }
      data[i+1]=key;
      }
   }
   else
   {
     for(j=1;j<getSize();j++)
      {
         key=data[j];
         i=j-1;
      //Inserts data[j] into sorted sequence data[1....j-1]

      while(i>=0 && *data[i]->city > *key->city)
      {
        data[i+1]=data[i];
        i=i-1;
      }
      data[i+1]=key;
      }
   }
}

/**----------------------------------------------------------------------
 *Description: This function accept the input to be sorted and initialize
 *             p and r. and pass these values to merge_Sort()
 *Input: int
 *Output: void
 *---------------------------------------------------------------------*/

void CensusData::mergeSort(int type)
{
   int p,r;
   p=0;
   r=getSize()-1;
   merge_Sort(type,p,r);
}

/**----------------------------------------------------------------------
 *Description: This function accepts p and r, which has been passed by
 *             mergeSort, it checks the condition and make the partition
 *             and gives the recursive call to it self until p<r
 *            condition gets false. and pass values p,q and r to Merge()
 *
 *Input:int
 *Output:void
 *-----------------------------------------------------------------------*/

void CensusData::merge_Sort(int type,int p,int r)
{
   int q;
   if(p < r)
   {
      q = (p+r)/2;
      merge_Sort(type,p,q);
      merge_Sort(type,q+1,r);
      Merge(type,p,q,r);
   }
}

/**----------------------------------------------------------------------
 *Description: This function used to conqure and combine the subproblems
 *             i.e. it combines sorted sub record and combine it to
 *             produce original record into sorted sequence
 *Input:int
 *Output:void
 *-----------------------------------------------------------------------*/

void CensusData::Merge(int type, int p, int q, int r)
{
   int n1,n2,k;
   n1=q-p+1;
   n2=r-q;
   //Let L[0...n1] and R[0...n2] be new vectors
   vector<Record*> L;
   vector<Record*> R;
   // Now L is left part of records
   //for loop below push data into vector L2147483647
   for(int i=0;i<n1;i++)
      L.push_back(data[p+i]);

   // R is right part of records
   //for loop below push data into vector R
   for(int j=0;j<n2;j++)
      R.push_back(data[q+j+1]);

    int i=0;
    int j=0;

   if(type==0)
   {
      for(k=p;k<=r;k++)
         {
            if((n1 != i) && ((n2 == j) || L[i]->population <= R[j]->population))
            {
               data[k]=L[i];
               i=i+1;
            }
            else
            {
               data[k]=R[j];
               j=j+1;
            }
         }
   }
   else
   {
      for(k=p;k<=r;k++)
      {
         if((n1 != i) && ((n2 == j) || *L[i]->city <= *R[j]->city))
         {
            data[k]=L[i];
            i=i+1;
         }
         else
         {
            data[k]=R[j];
            j=j+1;
         }
     }
   }
}

/**----------------------------------------------------------------------
 *Description:This function accept the input to be sorted and initialize
 *             p and r. and pass these values to Randomized_quicksort
 *Input: int
 *Output: void
 *---------------------------------------------------------------------*/

void CensusData::quickSort(int type)
{
   int p,r;
   p=0;
   r=getSize()-1;
   Randomized_quicksort(type,p,r);

}

/**----------------------------------------------------------------------
 *Description:This function is called in Randomized_quicksort()
 *             it gives recursive call to it self and makes partition
 *            this executes when p<r. it calls to Randomized_quicksort
 *
 *Input:int
 *Output:void
 *-----------------------------------------------------------------------*/

void CensusData::Randomized_quicksort(int type,int p,int r)
{
   if(p<r)
   {
      int q=Randomized_partition(type,p,r);
      Randomized_quicksort(type,p,q-1);
      Randomized_quicksort(type,q+1,r);
   }
}

/**----------------------------------------------------------------------
 *Description: This finction calls to random() whiv gives random
 *             integer value as a pivot, sets swipes records and
 *             set to data[r] which is used as key
 *
 *Input:int
 *Output: int - return value from Partition()
 *-----------------------------------------------------------------------*/

int CensusData::Randomized_partition(int type,int p,int r)
{
   int i;
   i=random(p,r);
   //swap A[r] with A[i]
   std::swap(data[r], data[i]);
   return Partition(type,p,r);
}

/**----------------------------------------------------------------------
 *Description: This function get call from Randomized_partition()
 *             here we calculate randam value pivot from given range
 *            "p to r" using uniform_int_generator. and to get different
 *             values every time we use default_random_engin to seed and
 *             generate different value
 *             we used time(0) for seeding because this is the thing
 *             which is increases constantly in systen evry second.
 *
 *Input:int
 *Output:int - return value -pivot
 *---------------------------------------------------------------------*/

int CensusData::random(int p,int r)
{
    //int pivot;
   std::default_random_engine randomGenerator;
   randomGenerator.seed(time(0));
   std::uniform_int_distribution<int> distribution(p,r);
   int pivot = distribution(randomGenerator);
   return pivot;
}

/**--------------------------------------------------------------------
 *Description: This function used to conqure and combine the subproblems
 *             i.e. it combines sorted sub record and combine it to
 *             produce original record into sorted sequence.
 *
 *Input:int
 *Output:int
 *---------------------------------------------------------------------*/

int CensusData::Partition(int type,int p,int r)
{
   if(type==0)
   {
   int x = data[r]->population;
   int i=p-1;
   for(int j=p;j<r;j++)
   {
      if(data[j]->population <= x)
      {
         i=i+1;
         std::swap(data[i], data[j]);
         //exchange data[i] with data[j];
      }
   }
        //exchange data[i+1] with data[r];
         std::swap(data[i+1], data[r]);
         return i+1;
   }
   else
   {
      string x = *data[r]->city;
      int i=p-1;
      for(int j=p;j<r;j++)
      {
         if(*data[j]->city <= x)
         {
            i=i+1;
            std::swap(data[i], data[j]);
            //exchange data[i] with data[j];
         }
      }
         //exchange data[i+1] with data[r];
         std::swap(data[i+1], data[r]);
         return i+1;
   }
}

/**----------------------------------------------------------------
                               EOF
 *-----------------------------------------------------------------*/
