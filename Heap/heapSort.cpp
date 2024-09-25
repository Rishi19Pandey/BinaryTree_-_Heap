//      heapSort.cpp

#include<bits/stdc++.h>
using namespace std;

void insert(vector<int> &heap , int size){
    int i = size, temp = heap[i];
    while(i > 1 && temp > heap[i/2]){
        heap[i] = heap[i/2];
        i = i/2;
    }
    heap[i] = temp;
}

void HeapSort(vector<int>&heap , int size){
    int i, j , temp = heap[1];
    heap[1] = heap[size];
    heap[size] = temp;
    i = 1;
    j = i*2;
    while(j <= size - 1){
        if(j < size-1 && heap[j] < heap[j+1]){
            j = j + 1;
        }
        if(heap[j] > heap[i]){
            swap(heap[i],heap[j]);
            i = j;
            j = j * 2;
        }
        else{
            break;
        }
    }
}

int main(){
   vector<int> heap = {0,10,60,30,50,90,80,70,20,40,100};
   int i = 0 ;
   for(i = 2 ; i < heap.size() ; i++){
        insert(heap,i);
   }
   cout<<"Heap : ";
   for(i = 1; i < heap.size(); i++){
        cout<<heap[i]<<" ";
   }
   cout<<endl;
   
   for(i = heap.size()-1 ; i > 1 ; i--){
        HeapSort(heap,i);
   }

   cout<<"Heap Sort : ";

   for(i = 1; i < heap.size() ; i++){
    cout<<heap[i]<<" ";
   }
   return 0;
}