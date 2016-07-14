/**-----------------------------------------------------------------
*@File : minpriority.cpp
*@Name:Tejas Patil  @ChicoStateID: 006949762
*@Assignment No: 05
*@Description:This file contains all function decleration for
         sspapp.cpp
*@Date: 15 May 2015
*-------------------------------------------------------------------*/

#ifndef SSPAPP_H_INCLUDED
#define SSPAPP_H_INCLUDED
#include "graph.h"

using namespace std;

class SSPapp
{
   public:
      void readGraph();//read graph
      void processQueries();//process imput
      bool don();


   private:
      Graph myGraph;
      bool done;


};

#endif // SSPAPP_H_INCLUDED
