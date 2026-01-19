#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& graph,int src,int dest,vector<bool>& visited){
  //we use stack for dfs since it is from top to bottom
  if(src==dest) return true;
  visited[src]=true;
  for(auto i:graph[src]){
    if(!visited[i]) {
      if(dfs(graph,i,dest,visited)) return true;
    }
  }
  return false;
}

void bfs(vector<vector<int>>& graph,int src,vector<bool>& visited){
  //we use queue for bfs since it is from left to right
  vector<vector<int>> levels;
  queue<int> q;
  q.push(src);
  visited[src]=true;

  while(!q.empty()){
    int sz =q.size();
    vector<int> level;

    for(int i=0;i<sz;i++){
      int node=q.front();
      q.pop();
      level.push_back(node);

      for(auto i:graph[node]){
        if(!visited[i]){
          visited[i]=true;
          q.push(i);
        }
      }
    }
    levels.push_back(level);
  }

  for(auto i:levels){
    for(auto j:i){
      cout<<j<<" ";
    }
    cout<<endl;
  }
}

int cntOfNodes(vector<vector<int>>& edges){
  int nodes=0;
  for(auto i:edges){
    nodes=max(nodes,max(i[0],i[1]));
  }
  return nodes+1; //since graph has 0 based index
}

int main(){
  vector<vector<int>> edges={ {0,1},{0,2}, {1,3}, {2,3} };
  int n=cntOfNodes(edges);
      //    0
      //   / \
      //  1   2
      //   \ /
      //    3
  
  vector<vector<int>> graph(n);

  //adjacency list to create graph from edges
  for(auto i:edges){
    graph[i[0]].push_back(i[1]);
    graph[i[1]].push_back(i[0]);
  }
  int nodes=graph.size();
  vector<bool> visited(nodes,false);

  if(dfs(graph,0,2,visited)) cout<<"Path exists"<<endl;
  else cout<<"No path exists"<<endl;

  bfs(graph,0,visited);

  return 0;
}