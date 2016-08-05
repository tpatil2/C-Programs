#include <iostream>
#include <queue>

using namespace std;

class node{

public:

  int data;
  node* left;
  node* right;

};

node* root=NULL;

node* getNewNode(int data){

  node* newnode = new node;
  newnode->data =  data;
  newnode->right = NULL;
  newnode->left = NULL;

  return newnode;
}

void print_inorder(node* curr){

  if(curr != NULL){
    std::cout << curr->data<<" " << std::endl;
    print_inorder(curr->left);
    print_inorder(curr->right);
  }

return;

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

node* insert_node(int arr[], int start, int end){

  if(start > end)
  return NULL;

  int mid = (start+end)/2;
  node* curr = new node;
  curr = getNewNode(arr[mid]);
  curr->left=insert_node(arr, start,mid-1);
  curr->right=insert_node(arr,mid+1,end);

  return curr;
}


int main(){

  int arr[]={1,2,3,4,5,6,7,8,9,10};
  int size = sizeof(arr)/sizeof(int);
  root = insert_node(arr,0,size-1);
  print_inorder(root);
  print_BFS(root);

  return 0;

}
