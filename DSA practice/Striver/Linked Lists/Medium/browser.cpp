#include<bits/stdc++.h>
 
using namespace std;

struct node{
    string data;
    node* next, *prev;
};

class browser{
    node *head, *tail, *base;
public:
    browser(){
        head = NULL;
        tail = NULL;
        base = NULL;
    }

    browser(string s){
        node* newnode = new node;
        newnode->data = s;
        newnode->prev = NULL;
        newnode->next = NULL;
        head = newnode;
        tail = newnode;
        base = newnode;
    }

    void homepage(string s){
        node* newnode = new node;
        newnode->data = s;
        newnode->prev = NULL;
        newnode->next = NULL;
        head = newnode;
        tail = newnode;
        base = newnode;
    }

    void visit(string s){
        node* newnode = new node;
        newnode->data = s;
        newnode->prev = NULL;
        if(base==tail){
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
            base = newnode;
        }
        else{
            while(tail!=base){
                node *temp = tail;
                tail=tail->prev;
                delete temp; 
            }
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode; 
            base = newnode;
        }
        
    }

    void back(int k){
        while(base->prev!=NULL && k){
            base = base->prev;
            k--;
        }
    }

    void forward(int k){
        while(base->next!=NULL && k){
            base = base->next;
            k--;
        }
    }

    void display(){
        node *cur = head;
        cout<<endl<<"Browser History:"<<endl;
        while(cur!=NULL){
            cout<<cur->data<<endl;
            cur = cur->next;
        }
        cout<<endl;
    }

    void current(){
        cout<<endl<<"Current Tab:"<<endl;
        cout<<base->data<<endl;
    }

};
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    browser l1;
    l1.homepage("google");
    l1.visit("insta");
    l1.visit("fb");
    l1.visit("youtube");
    l1.back(1);
    l1.display();
    l1.current();
    l1.back(5);
    l1.current();
    l1.forward(7);
    l1.current();
}