/**-----------------------------------------------------------------
*@File : Graph.cpp
*@Name:Tejas Patil  @ChicoStateID: 006949762
*@Assignment No: 05
*@Description:This file contains all function definations used to
               claculate shortest path using dikstra's Algorithm
               used minipriority queue in this algo

*@Date: 15 May 2015
*-------------------------------------------------------------------*/

#include "graph.h"
#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <utility>

using namespace std;

/**-------------------------------------------------------------------
*Description: This function accepts all vertices od graph
*INPUT: void
*OUTPUT: void
*-------------------------------------------------------------------*/
void Graph::addVertex(string name){

   Vertex *v = new Vertex();
   v->pi = "NIL";
   v->key= 100;
   tempvertices[name]=v;
}

/**-------------------------------------------------------------------
*Description: This is a function used to store all input vertices and
               their parent and key. to reuse it
*INPUT: void
*OUTPUT: void
*-------------------------------------------------------------------*/
void Graph::retain()
{

   for(map<string, Vertex*>::const_iterator it = tempvertices.begin()
   ;it !=tempvertices.end();++it )
   {
      Vertex *v = new Vertex();
      v->pi = "NIL";
      v->key= 100;
      vertices[it->first]=v;

   }

}
/**-------------------------------------------------------------------
*Description: This is a function used to store adjcency list of the
            graph in map.
*INPUT: void
*OUTPUT: void
*-------------------------------------------------------------------*/
void Graph::addEdge(string from, string to, int weight)
{
   Neighbor *n = new Neighbor();
   n->name = to;
   n->weight = weight;
   adjList[from].push_back(n);
}

/**-------------------------------------------------------------------
*Description: This is  a function which sorts the neighbors of vertex
               in decending order. used insertion sort logic from
               Assignment NO 2
*INPUT: void
*OUTPUT: void
*-------------------------------------------------------------------*/
void Graph::SortNeighbor()
{
   string tempname;
   int keytemp,i;

   for(map<string, vector<Neighbor*>>::const_iterator
    it = adjList.begin();it !=adjList.end();++it )
   {
      {
      for(unsigned int j = 1; j<it->second.size(); j++)
      {
         tempname = it->second[j]->name;
         keytemp = it->second[j]->weight;
         i=j-1;

       while(i>=0 &&(it->second[i]->name >= tempname))
       {
         it->second[i+1]->name  = it->second[i]->name;
         it->second[i+1]->weight = it->second[i]->weight;
         i=i-1;

       }

         it->second[i+1]->name = tempname;
         it->second[i+1]->weight = keytemp;

      }
      }
   }

}

/**-------------------------------------------------------------------
*Description: This is a function which accepts start and end vertices
               and find the shortest path between them
*INPUT: void
*OUTPUT: return value of type string
*-------------------------------------------------------------------*/
string Graph::getShortestPath(string from, string to)
{
   string u,path;
   string g=to;

   vertices[from]->key=0;

   for(map<string, Vertex*>::const_iterator it = vertices.begin()
   ;it !=vertices.end();++it )
   {
      mq.insert(it->first,it->second->key);
   }

   buidSSPTree(from);


   do
   {
      ssp.push_back(to);
      to=vertices.find(to)->second->pi;

   }while(to!="NIL");


   path="";


   while(!ssp.empty())
   {
      string mac=ssp.back();
      ssp.pop_back();
      path = path + mac + "->";
   }

   int h = vertices[g]->key;
   string len = to_string(h);

   path.pop_back();
   path.pop_back();




   path=path+" with length " + len;

   return path;
}


/**-------------------------------------------------------------------
*Description: This function is called in grt shortes path() it accepts
               source and construct tree from input source.
*INPUT: void
*OUTPUT: void
*-------------------------------------------------------------------*/
void Graph::buidSSPTree(string source)
{
   string u=source;

   while(!mq.Empty())
   {
      u=mq.extractMin();
      SortNeighbor();
      for(map<string, vector<Neighbor*>>::const_iterator it = adjList.
      begin();it !=adjList.end();++it )
      {
         if(it->first==u)
      {
      for(unsigned int i = 0; i<it->second.size(); i++)
      {
         relax(u,it->second[i]->name,it->second[i]->weight);
      }
      }
      }
   }
}


/**-------------------------------------------------------------------
*Description: This is a function which replace parent ad=nd key of the
               tree if it founds new key less than current key
*INPUT: void
*OUTPUT: void
*-------------------------------------------------------------------*/
void Graph::relax(string u, string v , int w)
{

   if(vertices[v]->key > (vertices[u]->key + w))
   {

   mq.decreaseKey(v ,(vertices[u]->key + w));
   vertices[v]->key = (vertices[u]->key + w);
   vertices[v]->pi = u;

   }

}
