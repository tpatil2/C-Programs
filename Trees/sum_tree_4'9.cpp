#include <iostream>
# include <queue>
using namespace std;

class node{
public:
  int data;
  node* left;
  node* right;
};

node* root = NULL;

node* getNewnode(int data){

  node* newNode= new node;
  newNode->data=data;
  newNode->left=NULL;
  newNode->right=NULL;

return newNode;
}

void print(node* curr){

  if(curr == NULL) return;
  print(curr->left);
  std::cout <<curr->data << " ";
  print(curr->right);

}

node* insertNode(node* curr,int newdata){

  if(curr == NULL) return getNewnode(newdata);
  else if(curr->data > newdata){
    curr->left=insertNode(curr->left,newdata);
  }
  else if(curr->data <= newdata){
    curr->right=insertNode(curr->right,newdata);
  }

  return curr;
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

bool path_sum(node* curr, int sum){

      if(curr==NULL){
        return (sum==0);//true or false
      }
      if(path_sum(curr->left, sum-curr->data)){
        return true;
      }
      if(path_sum(curr->right,sum-curr->data)){
        return true;
      }
return false;
}




int main(){


  root = insertNode(root,15);
  root = insertNode(root,11);
  root = insertNode(root,18);
  root = insertNode(root,10);
  root = insertNode(root,16);
  root = insertNode(root,12);
  root = insertNode(root,17);
  //root = insertNode(root,17);


  std::cout << "Inorder Tree" << std::endl;
  print(root);
  level_oreder_print(root);
  if(path_sum(root,4)) std::cout << "yes exists" << std::endl;
  return 0;
}
