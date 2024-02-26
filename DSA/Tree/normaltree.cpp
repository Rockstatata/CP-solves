#include<bits/stdc++.h>
 
using namespace std;

struct node{
    int data;
    node* left;
    node* right;

    node(){
        data = 0;
        left = NULL;
        right = NULL;
    }
};

class tree{
    node* root;
public:
    tree(){
        root = NULL;
    }
    tree(int data){
        root = new node;
        root->data = data;
    }
    void insertleftleft(int data){
        node* cur = root;
        while(cur->left!=NULL){
            cur = cur->left;
        }
        cur->left = new node;
        cur->left->data = data;
    }
    void insertleftright(int data){
        node* cur = root;
        while(cur->left!=NULL){
            cur = cur->left;
        }
        cur->right = new node;
        cur->right->data = data;
    }
    void insertrightright(int data){
        node* cur =root;
        while(cur->right!=NULL){
            cur = cur->right;
        }
        cur->right = new node;
        cur->right->data = data;
    }
    void insertrightleft(int data){
        node* cur =root;
        while(cur->right!=NULL){
            cur = cur->right;
        }
        cur->left = new node;
        cur->left->data = data;
    }
    int height(node* Node){
        if(Node==NULL) return 0;
        int lh = height(Node->left);
        int rh = height(Node->right);
        return 1+max(lh,rh);
    }
    int balancedheight(node* Node){
        if(Node==NULL) return 0;
        int lh = balancedheight(Node->left);
        if(lh==-1) return -1;
        int rh = balancedheight(Node->right);
        if(rh==-1) return -1;
        if(abs(lh-rh)>1) return -1;
        return 1+max(lh,rh);
    }
    node* getroot(){
        return root;
    }

    bool checkbalancedslow(node* Node){
        if(Node==NULL) return true;
        int lh = height(Node->left);
        int rh = height(Node->right);
        if(abs(rh-lh)>1)return false;
        bool left = checkbalancedslow(Node->left);
        bool right = checkbalancedslow(Node->right);
        if(!left || !right) return false;
        return true;
    }

    bool checkbalancedfast(node* Node){
        return balancedheight(Node)!=-1;
    }
        
};
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    tree t(1);
    t.insertleftleft(2);
    t.insertrightright(3);
    t.insertrightleft(4);
    t.insertrightright(5);
    //t.insertrightright(6);
    cout<<t.height(t.getroot())<<endl;
    cout<<(t.checkbalancedslow(t.getroot())?"Balanced":"Not Balanced")<<endl;
    cout<<(t.checkbalancedfast(t.getroot())?"Balanced":"Not Balanced")<<endl;
}