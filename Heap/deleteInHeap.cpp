//                  deleteInHeap.cpp

//      It is Also Work for Heap Sort


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void insertInHeap(int Arr[] , int size){
    int i = size ;
    int temp = Arr[i];
    while(i > 1 && temp > Arr[i/2]){
        Arr[i] = Arr[i/2];
        i = i / 2;
    }
    Arr[i] = temp;
}

int deleteInHeap(int Arr[] , int size){
    int temp = Arr[1];
    swap(Arr[1],Arr[size]);
    int i = 1 , j =  i * 2;
    while(j <= size-1){
        if(j < size - 1 && Arr[j] < Arr[j+1]){
            j = j+1;
        }
        if(Arr[j] > Arr[i]){
            swap(Arr[i], Arr[j]);
            i = j;
            j = (2*i) + 1;
        }
        else{
            break;
        }
    }
    return Arr[size];
}

int main(){
   int Arr[] = {0,10,60,30,50,90,80,70,20,40,100} , size = sizeof(Arr) / sizeof(Arr[0]);
   int i = 0;
   for(i = 1; i < size; i++){
        insertInHeap(Arr,i);
   }
   cout<<"Heap insertion : ";
   for(i = 1; i < size ; i++){
    cout<<Arr[i]<<" ";
   }

   cout<<endl;

   for(i = size-1 ; i  > 0 ; i--){
        cout<<"Deleted Element is : "<<deleteInHeap(Arr,i)<<endl;
   }

   cout<<"Heap Sort : ";
   for(i = 1; i < size; i++){
        cout<<Arr[i]<<" ";
   }
   return 0;
}