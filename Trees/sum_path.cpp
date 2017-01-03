#include <iostream>
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



void level_oreder_print(node* curr){

  std::cout << "\nLevel order Print" << std::endl;
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



//root to leaf only
bool path_sum(node* curr, int sum){

      if(curr==NULL){
        return (sum==0);
      }
      if(path_sum(curr->left,sum-curr->data)){
        return true;
      }
      if(path_sum(curr->right,sum-curr->data)){
        return true;
      }

return false;
}


int main(){


    root = insertNode(root, 45);
    root = insertNode(root, 35);
    root = insertNode(root, 33);
    root = insertNode(root, 56);
    root = insertNode(root, 60);
    root = insertNode(root, 49);

    print(root);
    level_oreder_print(root);
    if(path_sum(root,161)) std::cout << "path exists" << std::endl;

  return 0;
}
