/**-----------------------------------------------------------------
*@File : graph.h
*@Name:Tejas Patil  @ChicoStateID: 006949762
*@Assignment No: 05
*@Description:This file contains all function decleration for
            the function used in  graph.cpp
*@Date: 15 May 2015
*-------------------------------------------------------------------*/


#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <vector>
#include <map>
#include "minpriority.h"

using namespace std;

/**------------------------------------------------------------------
This is class graph
*-------------------------------------------------------------------*/
class Graph
{
   public:
      void addVertex(string name);//to add vertes
      void addEdge(string from, string to, int weight);//add edge
      string getShortestPath(string from, string to);
      //to find shortes path
      void retain();//to store vertices for further use
      void SortNeighbor();//to sort adjLIST

   private:


      class Vertex
      {
         public:
         string pi;
         int key;
      };



      class Neighbor
      {
         public:
         string name;
         int weight;

      };

      void buidSSPTree(string source);//build ssp tree
      void relax(string u, string v, int weight);//relax fun

      map<string, Vertex*> vertices;//map for vertices
      map<string, Vertex*> tempvertices;//temp map for vertices
      map<string, vector<Neighbor*>> adjList;//map for adjLIst
      MinPriorityQ mq;// minpriority queue object
      vector<string> ssp;// vector to store path
      int length=0;//variable to store lenth

};

#endif // GRAPH_H_INCLUDED
