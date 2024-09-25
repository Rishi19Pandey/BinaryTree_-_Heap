//          kosarajuAlgorithm.cpp


/* Hww many and what are the strongy connected components in Graph */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void insert(vector<int> G[] , int u , int v);
void dfs(int start , vector<int> GT[] , vector<int> &visited);
void topologicalSort(int vertex , vector<int> G[] , vector<int> &visited , stack<int> &st);
void dfs1(int node , vector<int> G[] , vector<int> &visited , stack<int> &st);
void reverseGraph(int vertex ,vector<int> GT[] , vector<int> G[] , vector<int> &visited);
int main(){
   int vertex = 8;
   vector<int> G[vertex];
   vector<int> visited(vertex , 0);
   stack<int> st;
   insert(G,0,1);
   insert(G,1,2); 
   insert(G,2,0);
   insert(G,2,3);
   insert(G,3,4);
   insert(G,4,5);
   insert(G,5,6);
   insert(G,6,4);
   insert(G,4,7);
   insert(G,6,7);
   topologicalSort(vertex , G , visited , st);
   vector<int> GT[vertex];
   int count = 0;
   reverseGraph(vertex,GT,G,visited);
   while(!st.empty()){
        int u = st.top();
        st.pop();
        if(!visited[u]){
            count++;
            dfs(u,GT,visited);
            cout<<endl;
        }
   }
   cout<<"There are "<<count<<" Strongly Connected Components ."<<endl;
   return 0;
}

void reverseGraph(int vertex ,vector<int> GT[], vector<int> G[] , vector<int> &visited){
   for(int i = 0 ; i < vertex ; i++){
        visited[i] = 0;
        for(auto it : G[i]){
            GT[it].push_back(i);
        }
   }
}

void dfs1(int node , vector<int> G[] , vector<int> &visited , stack<int> &st){
    visited[node] = 1;
    for(auto it : G[node]){
        if(!visited[it]){
            dfs1(it,G,visited,st);
        }
    }
    st.push(node);
}
void topologicalSort(int vertex , vector<int> G[] , vector<int> &visited ,stack<int> &st){
    for(int i = 0 ; i < vertex ; i++){
        if(!visited[i]){
            dfs1(i,G,visited,st);
        }
    }
}

void dfs(int start , vector<int> GT[] , vector<int> &visited){
    visited[start] = 1;
    cout<<start<<" ";
    for(auto i : GT[start]){
        if(visited[i] == 0){
            dfs(i,GT,visited);
        }
    } 
}

void insert(vector<int> G[] , int u , int v){
    G[u].push_back(v);
}