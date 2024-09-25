//          MorrisInorderTraversal.cpp

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

vector<int> MorrisInorderTraversal(struct node * root){
    vector<int> ans;
    struct node * cur = root;
    while(cur != NULL){
        if(cur -> left == NULL){
            ans.push_back(cur->val);
            cur = cur->right;
        }
        else{
            struct node * pre = cur -> left;
            while(pre->right && pre->right != cur){
                pre = pre->right;
            }
            if(pre->right == NULL){
                pre -> right = cur;
                cur = cur -> left;
            }
            else{
                pre->right = NULL;
                ans.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
    return ans;
}

int main(){
   struct node *root = insert(10);
   root->left = insert(20);
   root->right = insert(30);
   root->left->left = insert(11);
   root->left->right = insert(44);
   vector<int> res = MorrisInorderTraversal(root);
   for(auto it : res){
        cout<<it<<" ";
   }
   return 0;
}