//                  heapify.cpp                 (Max Heap)

#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &heap){
    int i = heap.size()-1,j,k;
    while(i > 0){
        k = i;
        j = k*2;
        while(j <= heap.size()-1){
            if(j < heap.size()-1 && heap[j] < heap[j+1]){
                j =  j + 1;
            }
            if(heap[k] < heap[j]){
                swap(heap[k],heap[j]);
                k = j;
                j = k * 2;
            }
            else{
                break;
            }
        }
        i--;
    }
}

int main(){
   vector<int> heap = {INT_MAX,50,30,20,60,10,90,70,80,100,40};
   heapify(heap);
   for(int i = 1 ; i < heap.size() ; i++){
    cout<<heap[i]<<" ";
   }
   return 0;
}