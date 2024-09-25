//          levelOrderTraversal.cpp

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node {
    int val;
    struct node *left ;
    struct node *right;
}*root = NULL;

void insert(){
   queue<struct node *> q;
   struct node * p1 = NULL;
   cout<<"Enter Root Element => ";
   int data,l,r;
   cin>>data;
   struct node * Node;
   Node = (struct node * )malloc(sizeof(struct node));
   Node -> val = data;
   Node -> left = NULL;
   Node -> right = NULL;
   q.push(Node);
   root = Node;
   while(!q.empty()){
        p1 = q.front();
        q.pop();
        cout<<"You want to add left child  "<<p1->val<< "  add DATA Otherwise 0 => ";
        cin>>l;
        if(l){
            Node = (struct node * )malloc(sizeof(struct node));
            Node -> val = l;
            Node -> left = NULL;
            Node -> right = NULL;
            p1->left = Node;
            q.push(Node);
        }
        cout<<"You want to add right child  "<< p1->val<< "  add DATA  Otherwise 0 => ";
        cin>>r;
        if(r){
            Node = (struct node * )malloc(sizeof(struct node));
            Node -> val = r;
            Node -> left = NULL;
            Node -> right = NULL;
            p1->right = Node;
            q.push(Node);
        }
   }
}

void levelOrderTraversal(struct node * temp){
    if(temp == NULL){
        return ;
    }
    queue<struct node *> q;
    q.push(temp);
    cout<<temp->val<<" ";
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp->left){
            q.push(temp->left);
            cout<<temp->left->val<<" ";
        }
        if(temp->right){
            q.push(temp->right);
            cout<<temp->right->val<<" ";
        }
    }
}

int main(){
   insert();
   cout<<"Level Order Traversal => ";
   levelOrderTraversal(root);
   return 0;
}