#include<bits/stdc++.h>
 
using namespace std;

struct node{
    int data;
    node *next;
};

class linkedlist{
    node* head;
public:
    linkedlist(){
        head=NULL;
    }

    void insert(int data){
        node *newnode= new node;
        newnode->data = data;
        newnode->next = NULL;
        if(head==NULL){
            head = newnode;
        }
        else{
            node *cur = head;
            while(cur->next!=NULL){
                cur=cur->next;
            }
            cur->next = newnode;
        }
    }

    void display(){
        node *cur = head;
        while(cur!=NULL){
            cout<<cur->data<<" ";
            cur=cur->next;
        }
        cout<<endl;
    }

    node* middleelement(){
        node* slow = head,*fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    linkedlist l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.insert(5);
    l1.display();
    node* mid = l1.middleelement();
    cout<<mid->data<<endl;
}