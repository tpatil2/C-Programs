#include <iostream>
using namespace std;



class node{
public:

int data;
node* left;
node* right;

};

node* root = NULL;

node* getNewnode(int data){
  node* temp= new node;
  temp->data = data;
  temp->left=NULL;
  temp->right=NULL;

  return temp;

}


void print(node* curr){

    if(curr!=NULL){
      print(curr->left);
      std::cout << curr->data << std::endl;
      print(curr->right);
    }

  return;
}


node* common_ancestor(node* root, int n1, int n2){

        if(root == NULL){
            return NULL;
        }
        if(root == n1 || root == n2){
            return root;
        }

        Node* left = lca(root.left, n1, n2);
        Node* right = lca(root.right, n1, n2);

        if(left != NULL && right != NULL){
            return root;
        }
        return left != NULL ? left : right;
}



node* insertNode(node* curr, int data){

  if(curr==NULL){
    curr= getNewnode(data);
    return curr;
  }
  if(data < curr->data) curr->left=insertNode(curr->left,data);
  else curr->right=insertNode(curr->right,data);

  return curr;
}


int main(){

  root = insertNode(root,10);
  root = insertNode(root,15);
  root = insertNode(root,5);
  root = insertNode(root,4);
  root = insertNode(root,13);
  root = insertNode(root,34);
  root = insertNode(root,33);
  root = insertNode(root,6);


  print(root);

  node* temp = common_ancestor(root,34,32);

std::cout << "common_ancestor is  "<< temp->data << std::endl;

  return 0;
}
