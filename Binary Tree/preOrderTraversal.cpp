//      preOrderTraversal.cpp

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

struct node *preorder(struct node * temp){
    if(temp){
        cout<<temp->val<<" ";
        preorder(temp->left);
        preorder(temp->right);
    }
}

int main(){
   struct node *root = insert(10);
   root->left = insert(20);
   root->right = insert(30);
   root->left->left = insert(11);
   root->left->right = insert(44);
   preorder(root);
   return 0;
}