#include<bits/stdc++.h>
 
using namespace std;

template<class T>
class BinaryTree{
    T data;
    node* left;
    node* right;
    node* parent;
public:
    BinaryTree(){
        parent = NULL;
        left = NULL;
        right = NULL;
    }
    BinaryTree(T value){
        data = value;
        parent = NULL;
        left = NULL;
        right = NULL;
    }
    BinaryTree(T value, BinaryTree<T>left, BinaryTree<T>right){
        data = value;
        parent = NULL;
        this->left = left;
        this->right = right;
    }
    int height(){
        
    }
};

 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
}