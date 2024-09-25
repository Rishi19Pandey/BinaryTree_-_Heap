//              postOrderTraversal.cpp

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node {
    int val;
    struct node *left ;
    struct node *right;
};

struct node * insert(int data){
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp-> val = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node *postOrder(struct node * temp){
    if(temp){
        postOrder(temp->left);
        postOrder(temp->right);
        cout<<temp->val<<" ";
    }
}

int main(){
   struct node *root = insert(10);
   root->left = insert(20);
   root->right = insert(30);
   root->left->left = insert(11);
   root->left->right = insert(44);
   postOrder(root);
   return 0;
}