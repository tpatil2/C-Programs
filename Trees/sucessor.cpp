#include <iostream>
#include <queue>

using namespace std;


class node{

public:

  int data;
  node* left;
  node* right;
  node* parent;
};

node* root = NULL;

node* getNewnode(int data){

  node* newNode = new node;
  newNode->data = data;
  newNode->left = NULL;
  newNode->right= NULL;

  return newNode;
}

void print(node* curr){

  if(curr!=NULL){
    std::cout << curr->data <<" " << std::endl;
    print(curr->left);
    print(curr->right);
  }
}

void print_BFS(node* curr){

    std::cout << "Inside BFS" << std::endl;
  //  print(curr);
    std::cout <<"\n"<< std::endl;

    if(curr == NULL) return;
    queue<node*> discovered;
    discovered.push(curr);

    while(!discovered.empty()){

        node * temp = discovered.front();
        discovered.pop();
        if(temp != NULL) std::cout <<  temp->data <<" " << std::endl;
        if(temp->left!=NULL) discovered.push(temp->left);
        if(temp->right!=NULL) discovered.push(temp->right);

    }

}


node* insertNode(node* curr, int data){

    if(curr==NULL){
      curr=getNewnode(data);
    }
    else if( data <= curr->data ){
      curr->left=insertNode(curr->left , data);
      curr->left->parent=curr;

    }else if( data > curr->data ){
      curr->right=insertNode(curr->right , data);
      curr->right->parent=curr;
    }

    return curr;
}

node* findmin(node* curr){

      while(curr->left != NULL) curr=curr->left;

  return curr;
}


//returns max of right sub-tree
node* findmax(node* curr){

      while(curr->right != NULL) curr=curr->right;

  return curr;
}


node* successor(node* curr){
  node* succ = new node;

  //case1: If node has right subtree
  if(curr->right != NULL) return findmin(curr->right);
  //case 2: if node is left child then its parent is cucessor
  succ = curr-> parent;
  // case 3:if node has right child
  while( succ != NULL && curr == succ->right){
      curr=succ;
      succ=succ->parent;
    }
    return succ;
}

node* predecessor(node* curr){
  node* pred = new node;
  // case 1 : if node has left subtree
  if(curr->left != NULL) return findmax(curr->left);
  //case 2 : if node is right child then its parent is predecessor
  pred = curr-> parent;
  // case 3 : if node is left child theb go upwards untill you find correct parent
  while( pred != NULL && curr == pred->left){
      curr=pred;
      pred=pred->parent;
    }
    return pred;
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

  root = insertNode(root, 45);
  root = insertNode(root, 35);
  root = insertNode(root, 33);
  root = insertNode(root, 56);
  root = insertNode(root, 60);
  root = insertNode(root, 49);

  print(root);

  print_BFS(root);

  level_oreder_print(root);

  node* temp=predecessor(root->left->left);
  if(temp!=NULL) std::cout << "succer of "<<root->left->left->data<< " is "<< temp->data << std::endl;
    else std::cout << "No successor" << std::endl;

  return 0;
}
