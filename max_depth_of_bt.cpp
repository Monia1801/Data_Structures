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

//recursive approach
int maxDepth(Node* root,int cnt){
  if(root==NULL) return cnt;
  int left=maxDepth(root->left,cnt+1);
  int right=maxDepth(root->right,cnt+1);
  return max(left,right);
}

//iterative approach using level order traversal
int mD(Node* root){
  if(root==NULL) return 0;
  queue<Node*> q;
  q.push(root);
  int cnt=0;
  while(!q.empty()){
    int size=q.size();
    cnt++;
    for(int i=0;i<size;i++){
      Node* n=q.front();
      q.pop();
      if(n->left!=NULL) q.push(n->left);
      if(n->right!=NULL) q.push(n->right);
    }
  }
  return cnt;
}

int main(){
  Node* root=new Node(10);
  root->left=new Node(20);
  root->right= new Node(30);
  root->left->left= new Node(40);
  root->left->right= new Node(50);
  root->right->right=new Node(70);
  root->right->right->left= new Node(60);
  
  cout<<maxDepth(root,0)<<endl;

  cout<<mD(root)<<endl;
  return 0;
}
