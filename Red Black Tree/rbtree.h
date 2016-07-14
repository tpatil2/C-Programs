/**
 * Nmae : Tejas patil chico st Id 006949762
 * @file rbtree.h Declaration of a red-black tree class.
 *
 * Note: The functions in this class should not do any I/O (except the
 * provided function rbPrintTree).
 *
 * @author Judy Challinger
 * @date 10/23/14
 */

#ifndef CSCI_311_RBTREE_H
#define CSCI_311_RBTREE_H

#include <string>
#include <vector>

using std::string;
using std::vector;

class RBTree {

public:

   RBTree();
   ~RBTree();

   void rbInsert(const string& key, const string& value);
   void rbDelete(const string& key, const string& value);
   vector<const string*> rbFind(const string& key);
   void rbPrintTree();

private:

   // Node is a private nested class - used only by RBTree.
   class Node {
   public:
      Node();
      Node(const string&, const string&, Node*);   // Node* s/b a pointer to nil
      ~Node();
      Node *parent;
      Node *left;
      Node *right;
      char color;
      string *key;
      string *value;
   };

   Node *root;          // pointer to the root of the red-black tree
   Node *nil;           // pointer to the single nil node

   // private accessors - must all use nil
   Node* rbTreeMinimum(Node*);
   Node* rbTreeMaximum(Node*);
   Node* rbTreeSuccessor(Node*);
   Node* rbTreePredecessor(Node*);
   Node* rbTreeSearch(Node*, const string&);
   void reverseInOrderPrint(Node*, int);

   // private mutators
   void leftRotate(Node*);
   void rightRotate(Node*);
   void rbInsertFixup(Node*);
   void rbDeleteFixup(Node*);
   void rbTransplant(Node*, Node*);

   // private mutators overloaded from public interface
   void rbInsert(Node*);
   void rbDelete(Node*);

   // do not modify anything above this line!
   // you may add private functions below (although you shouldn't need to)
   void rbPostorderTreeWalk(Node*);//used for free memory
};

#endif // CSCI_311_RBTREE_H
