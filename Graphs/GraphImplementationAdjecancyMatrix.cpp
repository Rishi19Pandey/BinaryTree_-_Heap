//         GraphImplementationAdjecancyMatrix.cpp

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class GraphImplementation{
    private:
        int numberOfVertex = 0;
        int numberOfEdge = 0;
        int startingVertex = 0;
        int EndingVertex = 0;
        int weight = 0;

    public:
        //------------------------------------------------------------------
        //           Display Adjacency Matrix                              |
        //------------------------------------------------------------------


        void displayAdjacencyMatrix(int * graph ,int numberOfVertex){
            int i =0 , j = 0;
            cout<<"Adjacency Matrix => "<<endl;
            for(i=0 ; i<numberOfVertex ; i++){
                for(j = 0 ; j< numberOfVertex ; j++){
                    cout<<*(graph + i * numberOfVertex + j)<<"  ";
                }
                cout<<endl;
            }
            cout<<endl;
        }
        //------------------------------------------------------------------
        //                  Undirected Graph                               |
        //------------------------------------------------------------------

        void undirectedGraph(int vertex , int edge){
            numberOfVertex = vertex;
            numberOfEdge = edge;
            int graph[numberOfVertex][numberOfVertex];
            int i = 0 , j = 0;
            for(i = 0 ; i < vertex ; i++){
                for(j = 0 ; j < vertex ; j++){
                    graph[i][j] = 0;
                }
            }
            cout<<"Undirected Graph "<<endl;
            cout<<"* Enter Starting , Ending Vertex *"<<endl;
             for(i = 0 ; i < numberOfEdge ; i++){
                cin>>startingVertex>>EndingVertex;
                graph[startingVertex][EndingVertex] = 1;
                graph[EndingVertex][startingVertex] = 1;
             }
            displayAdjacencyMatrix((int *)graph , vertex);
        }

        //------------------------------------------------------------------
        //                    directed Graph                               |
        //------------------------------------------------------------------


         void directedGraph(int vertex , int edge){
            numberOfVertex = vertex;
            numberOfEdge = edge;
            int graph[numberOfVertex][numberOfVertex];
            int i = 0 , j = 0;
            for(i = 0 ; i < vertex ; i++){
                for(j = 0 ; j < vertex ; j++){
                    graph[i][j] = 0;
                }
            }
            cout<<"directed Graph "<<endl;
            cout<<" * Enter Starting , Ending Vertex *"<<endl;
             for(int i = 0 ; i < numberOfEdge ; i++){
                cin>>startingVertex>>EndingVertex;
                graph[startingVertex][EndingVertex] = 1;
             }
            displayAdjacencyMatrix((int *)graph , vertex);
        }

         //------------------------------------------------------------------
        //              Weighted Undirected Graph                             |
        //------------------------------------------------------------------

         void weightedUndirectedGraph(int vertex , int edge){
            numberOfVertex = vertex;
            numberOfEdge = edge;
            int graph[numberOfVertex][numberOfVertex];
            int i = 0 , j = 0;
            for(i = 0 ; i < vertex ; i++){
                for(j = 0 ; j < vertex ; j++){
                    graph[i][j] = 0;
                }
            }
            cout<<" Weighted Undirected Graph "<<endl;
            cout<<" * Enter Starting Vertex , Ending Vertex , Weigth *"<<endl;
             for(int i = 0 ; i < numberOfEdge ; i++){
                cin>>startingVertex>>EndingVertex>>weight;
                graph[startingVertex][EndingVertex] = weight;
                graph[EndingVertex][startingVertex] = weight;
             }
            displayAdjacencyMatrix((int *)graph , vertex);
        }

         //------------------------------------------------------------------
        //              Weighted directed Graph                             |
        //------------------------------------------------------------------

         void weighteddirectedGraph(int vertex , int edge){
            numberOfVertex = vertex;
            numberOfEdge = edge;
            int graph[numberOfVertex][numberOfVertex];
            int i = 0 , j = 0;
            for(i = 0 ; i < vertex ; i++){
                for(j = 0 ; j < vertex ; j++){
                    graph[i][j] = 0;
                }
            }
            cout<<"Weighted Directed Graph "<<endl;
            cout<<" * Enter Starting Vertex , Ending Vertex , Weigth *"<<endl;
             for(int i = 0 ; i < numberOfEdge ; i++){
                cin>>startingVertex>>EndingVertex>>weight;
                graph[startingVertex][EndingVertex] = weight;
             }
            displayAdjacencyMatrix((int *)graph , vertex);
        }
};

int main(){ 
   GraphImplementation obj1;

   //   Undirected Graph

   obj1.undirectedGraph(5 , 6);
   cout<<endl;

   //   directed Graph

   obj1.directedGraph(4 , 4);
   cout<<endl;

   //   Weighted Undirected Graph

   obj1.weightedUndirectedGraph(4 , 5);
   cout<<endl;

   //   Weighted Directed Graph

   obj1.weighteddirectedGraph(4 , 5);
   cout<<endl;

   return 0;
}