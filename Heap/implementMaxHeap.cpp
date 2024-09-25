//                  implementMaxHeap.cpp

#include<bits/stdc++.h>
using namespace std;

void maxHeap(vector<int> &heap, int i){
    int temp = heap[i];
    while(i > 1 && temp > heap[i/2]){
        heap[i] = heap[i/2];
        i = i / 2;
    }
    heap[i] = temp;
}

int main(){
    int i;
   vector<int>heap = {INT_MAX,10,20,30,25,5,40,35};
   for(i = 1; i < heap.size() ; i++){
        maxHeap(heap,i);
   }
   cout<<"Max Heap : ";
   for(i = 1; i < heap.size() ; i++){
        cout<<heap[i]<<" ";
   }
   return 0;
}