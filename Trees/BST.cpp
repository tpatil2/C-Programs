#include <iostream>
#include <unistd.h>
#include <queue>

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

void print(node* curr){

  if(curr!=NULL){
    print(curr->left);
    std::cout << curr->data<<" ";
    print(curr->right);
  }

  return;
}

bool search(node* curr,int data){

  if(curr==NULL) return false;
  else if(data <= curr->data) return search(curr->left,data);
  else if(data > curr->data) return search(curr->right,data);
  else if(curr->data == data) return true;

}

node* insertNode(node* curr, int newdata){

  if(curr==NULL){
    curr=getNewnode(newdata);
  }else if(newdata <= curr->data){
      curr->left=(insertNode(curr->left,newdata));
  }else if(newdata > curr->data){
      curr->right=(insertNode(curr->right,newdata));
  }
return curr;

}

//returns min of right sub-tree
node* findmin(node* curr){

      while(curr->left != NULL) curr=curr->left;

  return curr;
}


//returns max of right sub-tree
node* findmax(node* curr){

      while(curr->right != NULL) curr=curr->right;

  return curr;
}

node* deleteNode(node* curr, int data){

  if(curr==NULL) return root;
  else if( data > curr->data) deleteNode(curr->right,data);
  else if( data < curr->data) deleteNode(curr->left,data);
  else if(curr->data==data){
    //case 1  both childs are NULL
    if(curr->left ==NULL && curr->right == NULL){
      delete curr;
      curr=NULL;
    }//case 2 only one child
    else if(curr->left == NULL){
          node* temp = new node;
          temp=curr;
          curr=curr->right;
          delete temp;
    }
    else if (curr->right == NULL) {
          node* temp= new node;
          temp=curr;
          curr=curr->left;
          delete curr;
    }//case 3 node has both childs
    else if(curr->left != NULL && curr->right != NULL ){

          node* temp = new node;
          temp=findmin(curr->right);
          curr->data=temp->data;
          curr->right = deleteNode(curr->right, temp->data);

    }
  }

return curr;
}

/*
node* successor(node* curr){
  node* succ = new node;
  if(curr->right != NULL) return findmin(curr->right);
  succ = curr-> parent;
  while( suuc != NULL && curr = succ->right){
      curr=succ;
      succ=succ->parent;
    }
    return succ;
}

node* predecessor(node* curr){
  node* pred = new node;
  if(curr->left != NULL) return findmax(curr->left);
  pred = curr-> parent;
  while( pred != NULL && curr = pred->left){
      curr=pred;
      pred=pred->parent;
    }
    return pred;
}
*/


void print_BFS(node* curr){

  queue<node*> discovered;
  queue<node*> visited;

    if(curr != NULL) discovered.push(curr);

    while(!discovered.empty()){

        node * temp = discovered.front();
        visited.push(temp);
        if(temp->left!=NULL) discovered.push(temp->left);
        if(temp->right!=NULL) discovered.push(temp->right);
        discovered.pop();
    }

    while(!visited.empty()){
      node* temp = visited.front();
      visited.pop();
      std::cout <<  temp->data <<" " << std::endl;
    }

}

int main(){


root = insertNode(root,15);
root = insertNode(root,18);
root = insertNode(root,11);
root = insertNode(root,16);
root = insertNode(root,17);
root = insertNode(root,12);
root = insertNode(root,10);

std::cout << "Inorder Tree" << std::endl;
print(root);

if(search(root,10)) std::cout << "Element found" << std::endl;
else std::cout << "\nNot found" << std::endl;

//deleteNode(root,15);

print_BFS(root);

return 0;

}
