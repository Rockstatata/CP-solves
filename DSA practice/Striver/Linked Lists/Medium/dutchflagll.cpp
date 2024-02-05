#include<bits/stdc++.h>
 
using namespace std;

struct node{
    int data;
    node *next,*prev;
};

class linkedlist{
    node* head, *tail;
public:
    linkedlist(){
        head=NULL;
        tail = NULL;
    }

    void insert(int data){
        node *newnode= new node;
        newnode->data = data;
        newnode->next = NULL;
        newnode->prev = NULL;
        if(head==NULL){
            head = newnode;
            tail = newnode;
        }
        else{
            tail->next=newnode;
            newnode->prev= tail;
            tail = newnode;
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

    void dutchnationalflag(){
        node* low = head, *mid = head, *high = tail;
        while(mid!=high->next){
            if(mid->data==0){
                swap(low->data,mid->data);
                low= low->next;
                mid= mid->next;
            }
            else if(mid->data==1){
                mid=mid->next;
            }
            else{
                swap(high->data,mid->data);
                high = high->prev;
            }
        }
    }
};
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    linkedlist l1;
    l1.insert(2);
    l1.insert(0);
    l1.insert(2);
    l1.insert(1);
    l1.insert(1);
    l1.insert(0);
    l1.display();
    l1.dutchnationalflag();
    l1.display();
}