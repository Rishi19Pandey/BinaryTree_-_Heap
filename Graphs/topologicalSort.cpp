//      topologicalSort.cpp

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void insert(vector<int> G[] , int u , int v){
    G[u].push_back(v);
}

void dfs(int node , vector<int> G[] , stack<int> &st , vector<int> &visited){
    visited[node] = 1;
    for(auto i : G[node]){
        if(visited[i] == 0){
            dfs(i,G,st,visited);
        }
    }
    st.push(node);
}

vector<int> topologicalSort(int vertex , vector<int> G[]){
   stack<int> st;
   vector<int> ans;
   vector<int> visited(vertex,0);

   for(int i = 0 ; i < vertex ; i++){
        if(visited[i] == 0){
            dfs(i,G,st,visited);
        }
   }
   
   while(!st.empty()){
        int u = st.top(); 
        st.pop();
        ans.push_back(u);
   }
   return ans;
}

int main(){
   int vertex = 5;
   vector<int> G[vertex];
//    insert(G,2,3);
//    insert(G,3,1);
//    insert(G,4,0);
//    insert(G,4,1);
//    insert(G,5,0);
//    insert(G,5,2);
    insert(G,0,1);
    insert(G,0,2);
    insert(G,1,3);
    insert(G,3,4);
   
   vector<int> res = topologicalSort(vertex,G);
   for(auto i : res){
      cout<<i<<" ";
   }
   return 0;
}