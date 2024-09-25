//          rightView.cpp

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

void rightV(struct node * temp , int size , vector<int> &ans){
    if(temp == NULL){
        return ;
    }
    if(size == ans.size()){
        ans.push_back(temp->val);
    }
    rightV(temp->right,size+1,ans);
    rightV(temp->left,size+1,ans);
}

vector<int> rightView(struct node *temp){
    vector<int> ans;
    rightV(temp,0,ans);
    return ans;
}

int main(){
   insert();
   cout<<"Right view of Binary Tree => ";
   vector<int> res = rightView(root);
   for(auto it : res){
        cout<<it<<" ";
   }
   cout<<endl;
   return 0;
}