#include <iostream>
#include <unistd.h>

using namespace std;


class node{
public:
  node* left;
  node* right;
  int data;
};

node* root =NULL;// initilize empty tree

node* getNewnode(int newdata){

  node* newNode = new node;
  newNode->data=newdata;
  newNode->left=NULL;
  newNode->right=NULL;

return newNode;

}

void print(node* newroot){

  if(newroot!=NULL){
    print(newroot->right);
    print(newroot->left);
    std::cout << "newroot->data"<<newroot->data << std::endl;
  }

  return;
}

bool search(node* newroot,int data){

  if(newroot==NULL) return false;
  else if(newroot->data == data) return true;
  else if(data <= newroot->data) return search(newroot->left,data);
  else if(data > newroot->data) return search(newroot->right,data);
}

node* insertNode(node* newroot, int newdata){

  if(newroot==NULL){
    newroot=getNewnode(newdata);
  }else if(newdata <= newroot->data){
      newroot->left=(insertNode(newroot->left,newdata));
  }else if(newdata > newroot->data){
      newroot->right=(insertNode(newroot->right,newdata));
  }
return newroot;

}

int main(){


root = insertNode(root,15);
root = insertNode(root,18);
root = insertNode(root,11);
root = insertNode(root,16);
root = insertNode(root,17);
root = insertNode(root,12);
root = insertNode(root,10);


print(root);

if(search(root,10)) std::cout << "Element found" << std::endl;
else std::cout << "Not found" << std::endl;

return 0;

}
