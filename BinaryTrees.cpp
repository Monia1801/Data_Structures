#include<bits/stdc++.h>
using namespace std;

class Node{
public:
  int data;
  Node* left;
  Node* right;
  Node(int data){
    this->data=data;
    left=NULL;
    right=NULL;
  }
};

void inOrder(Node* root){
  if(root==NULL) return;
  inOrder(root->left);
  cout<<root->data<<" ";
  inOrder(root->right);
}

void preOrder(Node* root){
  if(root==NULL) return;
  cout<<root->data<<" ";
  preOrder(root->left);
  preOrder(root->right);
}

void postOrder(Node* root){
  if(root==NULL) return;
  postOrder(root->left);
  postOrder(root->right);
  cout<<root->data<<" ";
}

vector<vector<int>> levelOrder(Node* root){ //tc is o(n) and sc is o(n)
  vector<vector<int>> ans;
  if(root==NULL) return ans;
  queue<Node*> q;
  q.push(root);
  while(!q.empty()){
    int size=q.size();
    vector<int> level;
    for(int i=0;i<size;i++){
      Node* n=q.front();
      q.pop();
      if(n->left!=NULL) q.push(n->left);
      if(n->right!=NULL) q.push(n->right);
      level.push_back(n->data);
    }
    ans.push_back(level);
  }
  return ans;
}

int main(){
  Node* newNode=new Node(10);
  newNode->left=new Node(20);
  newNode->right=new Node(30);

  cout<<"Depth first searches:"<<endl;

  cout<<"Inorder traversal: ";
  inOrder(newNode);
  cout<<endl;

  cout<<"Preorder traversal: ";
  preOrder(newNode);
  cout<<endl;

  cout<<"Postorder traversal: ";
  postOrder(newNode);
  cout<<endl;

  cout<<"Level Order traversal (or) Breadth First Search: ";
  vector<vector<int>> order=levelOrder(newNode);
  for(auto i:order){
    for(auto j:i) cout<<j<<" ";
  }
  return 0;
}