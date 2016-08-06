#include <iostream>
#include <queue>
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



node* insertNode(node* curr, int data){

  if(curr==NULL){
    curr= getNewnode(data);
    return curr;
  }
  if(data < curr->data) curr->left=insertNode(curr->left,data);
  else curr->right=insertNode(curr->right,data);

  return curr;
}


int Is_balanced(node* curr){

  if(curr==NULL) return 0;

    int lh = Is_balanced(curr->left);
    int rh = Is_balanced(curr->right);

      if(lh==-1 || rh==-1) return -1;
      if(abs(lh-rh) > 1) return -1;

    if(lh>rh) return lh+1;
      else return rh+1;

}




bool balanced_utility(node* curr){

    if(Is_balanced(curr) > -1) return true;

    else return false;

}



void level_oreder_print(node* curr){

  std::cout << "Level order Print" << std::endl;
    if(curr==NULL) return;

    queue<node*> q1;
    queue<node*> q2;
    q1.push(curr);

    while(!q1.empty() || !q2.empty()){

      while(!q1.empty()){
        node *temp1 = q1.front();
        q1.pop();
        std::cout << temp1->data<< " ";
        if(temp1->left != NULL) q2.push(temp1->left);
        if(temp1->right != NULL) q2.push(temp1->right);
      }
      std::cout<< std::endl;
      while(!q2.empty()){
        node *temp2 = q2.front();
        q2.pop();
        std::cout << temp2->data<< " ";
        if(temp2->left != NULL) q1.push(temp2->left);
        if(temp2->right != NULL) q1.push(temp2->right);
      }
      std::cout<< std::endl;

    }

  return;
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
  root = insertNode(root,6);
  

  level_oreder_print(root);
  if(balanced_utility(root)) std::cout << "Balanced" << std::endl;
  else std::cout << "Not balanced" << std::endl;
  return 0;
}
