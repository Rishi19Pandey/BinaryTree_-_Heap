//              AdjacencyList.cpp

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//---------------------------------------------
//            Undirected Gaph                 |
//---------------------------------------------

class Graph{
    public:

        vector<int> graph[5];
        int source , destination , i = 0;

        // Graph(int vertex){
        //     graph[vertex];
        // }

        void ImplementGraph(int edges){
            for(i = 0 ; i < edges ; i++){
                cout<<"Enter Source to destination : ";
                cin>>source>>destination;
                graph[source].push_back(destination);
                graph[destination].push_back(source);
            }
        }

        void display(){
            cout<<"Linked List Representation => "<<endl;
            for(i = 0 ; i < 5 ; i++){
                cout<<i<<" -> ";
                for(int itr : graph[i]){
                    cout<<itr<<" ";
                }
                cout<<endl;
            }
        }
};

int main(){
    Graph g;
    g.ImplementGraph(7);
    g.display();
   return 0;
}