//      graphImplement.cpp
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void insert(vector<int> G[] , int u , int v){
    G[u].push_back(v);
    G[v].push_back(u);
}

void dfs(vector<int> G[] , int start , vector<int> &visited){
    visited[start] = 1;
    cout<<start<<" ";
    for(auto i : G[start]){
        if(visited[i] == 0){
            dfs(G,i,visited);
        }
    }
}

void bfs(vector<int> G[] , int vertex){
    vector<int> visited1(vertex,0);
    visited1[0] = 1;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout<<u<<" ";
        for(auto i : G[u]){
           if(visited1[i] == 0){
             visited1[i] = 1;
            q.push(i);
           }
        }
    }
}

int main(){
   int vertex = 5;
//    cout<<"Enter number of Vertex => ";
//    cin>>vertex;
   vector<int> G[vertex];
   insert(G,2,1);
   insert(G,0,2);
   insert(G,0,4);
   insert(G,4,3);

   cout<<"DFS =>> ";
   vector<int> visited(vertex,0);
   dfs(G,0,visited);
   cout<<endl;
   cout<<"BFS =>> ";
   bfs(G,vertex);
   
   return 0;
}