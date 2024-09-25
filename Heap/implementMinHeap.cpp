//                  implementMinHeap.cpp

#include<bits/stdc++.h>
using namespace std;

void minHeap(vector<int> &heap , int i){
    int temp = heap[i];
    while(i > 1 && temp < heap[i/2]){
        heap[i] = heap[i/2];
        i = i/2;
    }
    heap[i] = temp;
}

int main(){
   vector<int> heap = {INT_MAX,50,30,60,80,20,100,90,70,10,40};
   int i = 0;
   for(i = 0 ; i < heap.size() ; i++){
       minHeap(heap,i);
   }
   cout<<"MIN Heap  :  ";
   for(i = 1 ; i < heap.size() ; i++){
        cout<<heap[i]<<" ";
   }
   return 0;
}