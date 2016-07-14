/**-----------------------------------------------------------------
*@File : sspapp.cpp
*@Name:Tejas Patil  @ChicoStateID: 006949762
*@Assignment No: 05
*@Description:This file contains all function definations for functions
               consol input output.
*@Date: 15 May 2015
*-------------------------------------------------------------------*/

#include <string>
#include "sspapp.h"
#include <iostream>

using namespace std;
/**-------------------------------------------------------------------
*Description: executition starts here and calls readgraph and process
               query
*INPUT: void
*OUTPUT: int return
*-------------------------------------------------------------------*/
int main()
{
   SSPapp s1;
   while(!cin.eof() && !s1.don())
   s1.readGraph();
   while(!cin.eof())
   s1.processQueries();

   return 0;
}

/**-------------------------------------------------------------------
*Description: This function accepts vertices and pass this to
               add vertex. and also accepts edges and weights
               and build adjList.
*INPUT: void
*OUTPUT: void
*-------------------------------------------------------------------*/
void SSPapp::readGraph()
{
   int no_v, no_e ,weight;
   string temp,first,second;

   cin >> no_v;

   for(int i=0;i<no_v;i++)
   {
      cin >> temp;
      myGraph.addVertex(temp);
   }
      cin>> no_e;

   for(int i=0; i<no_e;i++)
   {
      cin>>first;
      cin>>second;
      cin>>weight;
      myGraph.addEdge(first ,second , weight);
   }

   done=true;

}


/**-------------------------------------------------------------------
*Description: this accepts start and end and prints path.
*INPUT: void
*OUTPUT: void
*-------------------------------------------------------------------*/
void SSPapp::processQueries()
{

   myGraph.retain();
   string str;
   string start,End;
   cin>>start;
   if(!start.empty())
   {
      cin>>End;
      str=myGraph.getShortestPath(start, End);
      cout<<str<<endl;
   }
}


/**-------------------------------------------------------------------
*Description:used retuen values to check end of file
*INPUT: void
*OUTPUT: bool
*-------------------------------------------------------------------*/

bool SSPapp::don()
{
   return done;
}
