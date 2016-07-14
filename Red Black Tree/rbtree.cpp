/**-----------------------------------------------------------------
*@File : rbtree.cpp
*@Name:Tejas Patil  @ChicoStateID: 006949762
*@Assignment No: 04
*@Description:This file contains all function definations for operations
*             on Red-Black-Tree like Insert, Delete and find for
               single and multiple keys.
*@Date: 18 April 2015
*-------------------------------------------------------------------*/

#include <iostream>
#include <iomanip>
#include "rbtree.h"
#include <string>
#include <vector>

using std::cout;
using std::setw;
using std::endl;

using namespace std;

/*-----------------------------------------------------------------------
*Description: This is print function which prints Red-Black Tree
               this calls to reverseInOrderPrint() function which
               prints colour, key and data
*INPUT: void
*OUTPUT: void
*----------------------------------------------------------------------*/

void RBTree::rbPrintTree()
{
  reverseInOrderPrint(root, 0);
}

/*-----------------------------------------------------------------------
*Description: This is print function which prints Red-Black Tree
               which prints colour, key and data in Inorder traversal
*INPUT: void
*OUTPUT: void
*----------------------------------------------------------------------*/

void RBTree::reverseInOrderPrint(Node *x, int depth) {
   if ( x != nil ) {
      reverseInOrderPrint(x->right, depth+1);
      cout << setw(depth*4+4) << x->color << " ";
      cout << *(x->key) << " " << *(x->value) << endl;
      reverseInOrderPrint(x->left, depth+1);
   }
}

/*-----------------------------------------------------------------------
*Description:This is constructor for Red-Black Tree which initializes
            root and nil node
*INPUT: void
*OUTPUT: void
*----------------------------------------------------------------------*/
RBTree::RBTree()
{
  nil = new Node();
  root = nil;
}

/*-----------------------------------------------------------------------
*Description: This function used for postorder traversal which is used
               for tree destructor to free memory
*INPUT:void
*OUTPUT:void
*----------------------------------------------------------------------*/

void RBTree::rbPostorderTreeWalk(Node* x)
{
   if(x!=nil)
   {
   rbPostorderTreeWalk(x->left);
   rbPostorderTreeWalk(x->right);
   delete x;
   }
}

/*-----------------------------------------------------------------------
*Description:This function used for postorder traversal which is used
               for tree destructor to free memory
*INPUT:void
*OUTPUT:void
*----------------------------------------------------------------------*/
RBTree::~RBTree()
{
   if(root!=nil)
   {
      rbPostorderTreeWalk(root);
      delete nil;
   }
}

/*-----------------------------------------------------------------------
*Description:This is node constructor which initalizes attrubites of
               node like parent, left, righr, key, value and color
*INPUT:void
*OUTPUT:void
*----------------------------------------------------------------------*/

RBTree::Node::Node()
{
   parent = NULL;
   left = NULL;
   right = NULL;
   key = NULL;
   value = NULL;
   color = 'B';
}

/*-----------------------------------------------------------------------
*Description:this is node default destructor whis frees memory assigned
            to node at the end of program
*INPUT:void
*OUTPUT:void
*----------------------------------------------------------------------*/

RBTree::Node::~Node()
{
   delete key;
   delete value;
}

/*-----------------------------------------------------------------------
*Description:This parametarised constructor which assignes the attributes
               like key and values which are passed by parameter
*INPUT:void
*OUTPUT:void
*----------------------------------------------------------------------*/

RBTree::Node::Node(const string& Key, const string& Data, Node *Nl)
{
   key = new string(Key);
   value = new string(Data);
   parent = Nl;
   left = Nl;
   right = Nl;
   color = 'R';

}

/*-----------------------------------------------------------------------
*Description:This function accepts key and data whch has to me
            inserted on Red Back Tree and pass it to rbInsert()
*INPUT:void
*OUTPUT:void
*----------------------------------------------------------------------*/

void RBTree::rbInsert(const string& key, const string& value)
{
   Node *z;
   z=new Node(key, value, nil);
   rbInsert(z);
}

/*-----------------------------------------------------------------------
*Description: This function inserts node in Red Black Tree
*INPUT: void
*OUTPUT: void
*----------------------------------------------------------------------*/

void RBTree::rbInsert(Node* z)
{
   Node* y = nil;
   Node* x = root;
   while (x != nil)
   {
      y = x;
      if (*z->key < *x->key)
      {x=x->left;}
   else
      {
         x = x->right;
      }
   }
   z->parent = y;

   if (y == nil)
      {
         root = z;
      }
   else if (*z->key < *y->key)
      {
         y->left = z;
      }
   else
      {
         y->right = z;
      }
      z->left = nil;
      z->right = nil;
      z->color = 'R';

      rbInsertFixup(z);
}

/*-----------------------------------------------------------------------
*Description: This function manage modification appears which forms at
               the time of insert new node . this function retains
               red black tree properties.
*INPUT:void
*OUTPUT:void
*----------------------------------------------------------------------*/

void RBTree::rbInsertFixup(Node* z)
{
   while (z->parent->color == 'R')
   {
      if (z->parent == z->parent->parent->left)
      {
         Node* y=z->parent->parent->right;
         if (y->color == 'R')
      {
         z->parent->color = 'B';
         y->color = 'B';
         z->parent->parent->color = 'R';
         z = z->parent->parent;
      }
         else
         {
            if (z == z->parent->right)
         {
            z = z->parent;
            leftRotate(z);
         }
         z->parent->color = 'B';
         z->parent->parent->color = 'R';
         rightRotate(z->parent->parent);
         }
      }
    else
      {
         Node* y=z->parent->parent->left;
         if (y->color == 'R')
         {
            z->parent->color = 'B';
            y->color = 'B';
            z->parent->parent->color = 'R';
            z = z->parent->parent;
         }
      else
         {
            if (z == z->parent->left)
            {
               z = z->parent;
               rightRotate(z);
            }
        z->parent->color = 'B';
        z->parent->parent->color = 'R';
        leftRotate(z->parent->parent);
      }
    }
  }
  root->color = 'B';
}

/*-----------------------------------------------------------------------
*Description:This function finds all keys in red black tree returns
               vector containing these keys.this fiunction uses
               predecessor and sucessor to find out multiple keys
*INPUT: Void
*OUTPUT: Vector
*----------------------------------------------------------------------*/

vector<const string*> RBTree::rbFind(const string& key)
{
   Node *z = rbTreeSearch(root, key);
   vector<const string*> key_vector;
   if(z != nil)
   {
      Node *p =  rbTreePredecessor(z);
      Node *s = rbTreeSuccessor(z);

      key_vector.push_back(z->value);

      while(s != nil)
      {
         if (s != z && *s->key == key)
         {
            key_vector.push_back(s->value);
         }
         s = rbTreeSuccessor(s);
      }
      while(p != nil)
      {
         if (p != z && *p->key == key)
         {
            key_vector.push_back(p->value);
         }
         p = rbTreePredecessor(p);
      }
   }
   return key_vector;
}



/*-----------------------------------------------------------------------
*Description: This function finds and deletes all keys in red black
               tree this fiunction uses.it calls rbdelete() and pass
               respective node to delete.
               predecessor and sucessor to find out multiple keys
*INPUT: Void
*OUTPUT: void
*----------------------------------------------------------------------*/

void RBTree::rbDelete(const string& key, const string& data)
{
   vector<Node*> key_data_vector;
   Node *z = rbTreeSearch(root, key);

   if(z != nil)
   {
      Node *s = rbTreeSuccessor(z);
      Node *p = rbTreePredecessor(z);

    if(*z->value==data)
    {
      key_data_vector.push_back(z);
    }

   while(p!=nil)
   {
      if (p != z && *p->key == key && *p->value == data)
      {
         key_data_vector.push_back(p);
      }
      p = rbTreePredecessor(p);
   }

   while(s != nil)
   {
      if (s != z && *s->key == key && *s->value == data)
      {
         key_data_vector.push_back(s);
      }
      s = rbTreeSuccessor(s);
    }

   for(unsigned int i = 0; i < key_data_vector.size(); i++)
   {
      rbDelete(key_data_vector[i]);
   }
   }
}


/*-----------------------------------------------------------------------
*Description: This function  delets the node and call rbfixup() to
            modify tree according to properties of RBT
*INPUT:void
*OUTPUT:void
*----------------------------------------------------------------------*/

void RBTree::rbDelete(Node* z)
{
   Node* y = z;
   Node* x;
   char yOriginalColor = y->color;
   if (z->left == nil)
   {
      x = z->right;
      rbTransplant(z, z->right);
   }
   else if(z->right == nil)
   {
      x = z->left;
      rbTransplant(z, z->left);
   }
   else
   {
      y = rbTreeMaximum(z->left);
      yOriginalColor = y->color;
      x = y->left;
      if (y->parent == z)
      x->parent = y;
      else
      {
         rbTransplant(y, y->left);
         y->left = z->left;
         y->left->parent = y;
      }
      rbTransplant(z, y);
      y->right = z->right;
      y->right->parent= y;
      y->color = z->color;
   }
   if(yOriginalColor == 'B')
   rbDeleteFixup(x);
   z->left = NULL;
   z->right = NULL;
   delete z;
}

/*-----------------------------------------------------------------------
*Description: This function modifies Red Black tree after deletinf node
*INPUT: void
*OUTPUT: void
*----------------------------------------------------------------------*/

void RBTree::rbDeleteFixup(Node* x)
{
   while (x != root && x->color == 'B')
   {
      if (x == x->parent->left)
      {
         Node* w = x->parent->right;
         if (w->color == 'R')
      {
         w->color = 'B';
         x->parent->color = 'R';
         leftRotate(x->parent);
         w = x->parent->right;
      }
      if (w->left->color == 'B' && w->right->color == 'B')
      {
         w->color = 'R';
         x = x->parent;
      }
      else
      {
         if (w->right->color == 'B')
         {
            w->left->color = 'B';
            w->color = 'R';
            rightRotate(w);
            w = x->parent->right;
         }
         w->color = x->parent->color;
         x->parent->color = 'B';
         w->right->color = 'B';
         leftRotate(x->parent);
         x = root;
      }
      }
   else
      {
         Node* w = x->parent->left;
         if (w->color == 'R')
      {
         w->color = 'B';
         x->parent->color = 'R';
         rightRotate(x->parent);
         w = x->parent->left;
      }
      if (w->right->color == 'B' && w->left->color == 'B')
      {
         w->color = 'R';
         x = x->parent;
      }
      else
      {
         if (w->left->color == 'B')
         {
            w->right->color = 'B';
            w->color = 'R';
            leftRotate(w);
            w = x->parent->left;
         }
         w->color = x->parent->color;
         x->parent->color = 'B';
         w->left->color = 'B';
         rightRotate(x->parent);
         x = root;
      }
      }
  }
  x->color = 'B';
}

/*-----------------------------------------------------------------------
*Description: This function returns sucessor of given node.
*INPUT:void
*OUTPUT: node y as sucessor
*----------------------------------------------------------------------*/

RBTree::Node* RBTree::rbTreeSuccessor(Node* x)
{
   if (x->right != nil)
   return rbTreeMinimum(x->right);
   Node* y = x->parent;
   while (y != nil && x == y->right)
   {
      x = y;
      y = y->parent;
   }
   return y;
}
/*-----------------------------------------------------------------------
*Description: This function returns sucessor of given node.
*INPUT: void
*OUTPUT: node y as predecessor
*----------------------------------------------------------------------*/

RBTree::Node* RBTree::rbTreePredecessor(Node* x)
{
   if (x->left != nil)
   return rbTreeMaximum(x->left);
   Node* y = x->parent;
   while (y != nil && x == y->left)
   {
      x = y;
      y = y->parent;
   }
   return y;
}

/*-----------------------------------------------------------------------
*Description: This function returns node with minimum values in left
               sub tree of given node
*INPUT: void
*OUTPUT: void
*----------------------------------------------------------------------*/

RBTree::Node* RBTree::rbTreeMinimum(Node* x)
{
   while (x->left != nil)
   x = x->left;
   return x;
}

/*-----------------------------------------------------------------------
*Description:This function returns node with minimum values in right
               sub tree of given node
*INPUT: void
*OUTPUT: void
*----------------------------------------------------------------------*/

RBTree::Node* RBTree::rbTreeMaximum(Node* x)
{
   while (x->right != nil)
   x = x->right;
   return x;
}

/*-----------------------------------------------------------------------
*Description: this function returns node with respective to given key
*INPUT:void
*OUTPUT: retun found node
*----------------------------------------------------------------------*/

RBTree::Node* RBTree::rbTreeSearch(Node* x, const string& k)
{
   if (x == nil)
   return x;
   else if (k == *x->key)
   return x;
   if (k < *x->key)
   return rbTreeSearch(x->left, k);
   else return rbTreeSearch(x->right, k);
}

/*-----------------------------------------------------------------------
*Description: this function does right rotation
*INPUT:void
*OUTPUT:void
*----------------------------------------------------------------------*/


void RBTree::rightRotate(Node* x)
{
   Node* y = x->left;
   x->left = y->right;
   if (y->right != nil)
      y->right->parent = x;
      y->parent = x->parent;
   if (x->parent == nil)
      root = y;
   else if (x == x->parent->right)
      x->parent->right = y;
   else
      x->parent->left = y;
      y->right = x;
      x->parent = y;
}


/*-----------------------------------------------------------------------
*Description: This function does left rotation
*INPUT:void
*OUTPUT:void
*----------------------------------------------------------------------*/

void RBTree::leftRotate(Node* x)
{
   Node* y = x->right;
   x->right = y->left;
   if (y->left != nil)
      y->left->parent = x;
      y->parent = x->parent;
   if (x->parent == nil)
      root = y;
   else if ( x == x->parent->left)
      x->parent->left = y;
   else
      x->parent->right = y;
      y->left = x;
      x->parent = y;
}

/*-----------------------------------------------------------------------
*Description: this function swith between two given node u and v
*INPUT: void
*OUTPUT: void
*----------------------------------------------------------------------*/

void RBTree::rbTransplant(Node* u, Node* v)
{
   if (u->parent == nil)
   root = v;
   else if ( u ==u->parent->left)
      u->parent->left = v;
   else
      u->parent->right = v;
   v->parent = u->parent;
}

