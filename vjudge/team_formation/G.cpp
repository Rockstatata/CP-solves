#include<bits/stdc++.h>
 
using namespace std;

struct node{
    int data;
    node* next;
};

class Linked_list{
public:
    node* head;
    Linked_list(){
        head = NULL;
    }

    void insert(int data){
        node *newnode = new node;
        newnode->data =data;
        newnode->next = NULL;
        if(head==NULL){
            head=newnode;
        }
        else{
            node *cur = head;
            while(cur->next!=NULL){
                cur= cur->next;
            }
            cur->next = newnode;
        }
    }

    node* mergelist(node* first, node* second){
        if (!first) 
            return second; 
    
        if (!second) 
            return first; 
    
        if (first->data < second->data) 
        { 
            first->next = mergelist(first->next,second); 
            return first; 
        } 

        else
        { 
            second->next = mergelist(first,second->next); 
            return second; 
        } 
    }

    void display(){
        node *cur = head;
        while(cur!=NULL){
            cout<<cur->data<<" ";
            cur = cur->next;
        }
        cout<<endl;
    }
};
 
int main(){
     int t;
     cin>>t;
     
     while (t--)
     {
        Linked_list l1,l2,l3;
        int n,m;
        cin>>n;
        int data;
        while(n--){
            cin>>data;
            l1.insert(data);
        }
        cin>>m;
        while(m--){
            cin>>data;
            l2.insert(data);
        }
        l3.head = l3.mergelist(l1.head,l2.head);
        l3.display();
     }
}