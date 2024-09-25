//              detectCycleInUndirectedGraph.cpp

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void insert(vector<int> G[] , int u , int v){
    G[u].push_back(v);
    G[v].push_back(u);
}

void dfs(int node , vector<int> G[] , vector<int> &visited){
    visited[node] = 1;
    cout<<node<<" ";
    for(auto it : G[node]){
        if(visited[it] == 0){
            dfs(it,G,visited);
        }
    }
}

bool isCycle(int start , vector<int> G[] , vector<int> &visited){
    queue<pair<int,int>> q;
    visited[start] = 1;
    q.push({start,-1});
    int u , v;
    while(!q.empty()){
        u = q.front().first;
        v = q.front().second;
        q.pop();
        for(auto it : G[u]){
            if(!visited[it]){
                visited[it] = 1;
                q.push({it,u});
            }
            else if(v != it){
                return true;
            }
        }
    }
    return false; 
}

bool check(int vertex , vector<int> G[] , vector<int> &visited){
    for(int i = 0 ; i< vertex ; i++){
        if(!visited[i]){
            if(isCycle(i,G,visited)){
                return true;
            }

        }
   }
   return false;
}

int main(){
   int vertex, u  , v  , start , edge;
   cout<<"Enter size of vertex => ";
   cin>>vertex;
   cout<<"Enter size of Edge =>";
   cin>>edge;
   vector<int> G[vertex];
   cout<<"Pair of Edges "<<endl;
   for(int i = 0 ; i < edge ; i++){
        cin>>u>>v;
        insert(G,u,v);
   }
   vector<int> visited(vertex,0);
    bool res = check(vertex , G, visited);
   if(res){
      cout<<"There is Cycle";
   }
   else if(!res){
        cout<<"There is no Cycle";
   }
//    dfs(start , G , visited);
//    if(isCycle(start,G,visited)){
//       cout<<"There is Cycle";
//    }
//    else{
//     cout<<"There is no cycle";
//    }
   return 0;
}