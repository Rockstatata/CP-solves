#include<bits/stdc++.h>
 
using namespace std;

struct Node{
    Node *left;
    int data;
    Node *right;
} *root = NULL;

void Insert(int key){
    Node *t = root;
    Node *r = NULL, *p;

    if(root==NULL){
        p = new Node;
        p->data = key;
        p->left = NULL;
        p->right = NULL;
        root = p;
        return;
    }
    
    while(t!=NULL){
        r=t;
        if(key<t->data){
            t = t->left;
        }
        else if(key>t->data){
            t = t->right;
        }
        else return;
    }

    p = new Node;
    p->data = key;
    p->left = NULL;
    p->right = NULL;
    if(key<r->data) r->left = p;
    else r->right = p;
}

void Inorder(struct Node *p)
{
    if(p){
        Inorder(p->left);
        printf("%d ",p->data);
        Inorder(p->right);
    }
}

struct Node * Search(int key)
{
    Node *t=root;
    
    while(t!=NULL){
        if(key==t->data)
            return t;
        else if(key<t->data)
            t=t->left;
        else
            t=t->right;
    }
    return NULL;
}

struct Node *RInsert(struct Node *p,int key)
{
    struct Node *t=NULL;
    
    if(p==NULL){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=key;
        t->lchild=t->rchild=NULL;
        return t;
    }
    if(key < p->data)
    p->lchild=RInsert(p->lchild,key);
    else if(key > p->data)
    p->rchild=RInsert(p->rchild,key);
    
    return p;
}


 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
}