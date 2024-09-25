//      InorderTraversal.cpp

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

struct node *inorder(struct node * temp){
    if(temp){
        inorder(temp->left);
         cout<<temp->val<<" ";
        inorder(temp->right);
    }
}

int main(){
   struct node *root = insert(10);
   root->left = insert(20);
   root->right = insert(30);
   root->left->left = insert(11);
   root->left->right = insert(44);
   inorder(root);
   return 0;
}