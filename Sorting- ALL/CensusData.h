/**---------------------------------------------------------
 * @file CensusData.h   Declaration of the CensusData class.
 *
 * @author Judy Challinger
 * @date 2/22/13
 * @edited by Tejas Patil Chico State ID-006949762
 * @date 3/5/2015
 ----------------------------------------------------------*/

#ifndef CSCI_311_CENSUSDATA_H
#define CSCI_311_CENSUSDATA_H

#include <vector>
using std::ifstream;
using std::string;
using std::vector;

class CensusData {
public:
   static const int POPULATION = 0;       // type of sort
   static const int NAME = 1;
   ~CensusData();
   void initialize(ifstream&);            // reads in data
   int getSize(){return data.size();}
   void print();                          // prints out data
   void insertionSort(int);               // sorts data using insertionSort
   void mergeSort(int);                   // sorts data using mergeSort
   void quickSort(int);                   // sorts data using quickSort
private:
   class Record {                         // declaration of a Record
   public:
      string* city;
      string* state;
      int population;
      Record(string&, string&, int);
      ~Record();
   };
   vector<Record*> data;                  // data storage

// private helper functions here

   void merge_Sort(int type,int p,int r);
   void Merge(int type,int p,int q,int r);
   int Partition(int type,int p,int r);
   void Randomized_quicksort(int type,int p,int r);
   int Randomized_partition(int type,int p,int r);
   int random(int p,int r);
};
#endif // CSCI_311_CENSUSDATA_H
