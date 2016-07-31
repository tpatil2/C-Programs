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
    std::cout << "newroot->data"<<newroot->data << std::endl;
    print(newroot->right);
    print(newroot->left);
  }

  return;
}

bool search(node* newroot,int data){

  if(newroot==NULL) return false;
  else if(data <= newroot->data) return search(newroot->left,data);
  else if(data > newroot->data) return search(newroot->right,data);
  else if(newroot->data == data) return true;

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

//returns min of right sub-tree
node* findmin(node* newroot){

      while(newroot->left != NULL) newroot=newroot->left;

  return newroot;
}

node* deleteNode(node* newroot, int data){

  if(newroot==NULL) return root;
  else if( data > newroot->data) deleteNode(newroot->right,data);
  else if( data < newroot->data) deleteNode(newroot->left,data);
  else if(newroot->data==data){
    //case 1  both childs are NULL
    if(newroot->left ==NULL && newroot->right == NULL){
      delete newroot;
      newroot=NULL;
    }//case 2 only one child
    else if(newroot->left == NULL){
          node* temp = new node;
          temp=newroot;
          newroot=newroot->right;
          delete temp;
    }
    else if (newroot->right == NULL) {
          node* temp= new node;
          temp=newroot;
          newroot=newroot->left;
          delete newroot;
    }//case 3 node has both childs
    else if(newroot->left != NULL && newroot->right != NULL ){

          node* temp = new node;
          temp=findmin(newroot->right);
          newroot->data=temp->data;
          newroot->right = deleteNode(newroot->right, temp->data);

    }
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

deleteNode(root,15);

print(root);


return 0;

}
