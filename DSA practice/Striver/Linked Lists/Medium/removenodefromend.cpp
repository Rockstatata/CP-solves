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

    void deletemid(){
        node* slow = head,*fast = head, *prev = NULL;
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;
        delete slow;
    }

    node* DeleteNthnodefromEnd(int N) {
    // Create two pointers, fastp and slowp
    node* fastp = head;
    node* slowp = head;

    // Move the fastp pointer N nodes ahead
    for (int i = 0; i <= N; i++){
        fastp = fastp->next;
    }

    // If fastp becomes NULL,
    // the Nth node from the end is the head
    if (fastp == NULL)
        return head->next;

    // Move both pointers until fastp reaches the end
    while (fastp->next != NULL) {
        fastp = fastp->next;
        slowp = slowp->next;
    }

    // Delete the Nth node from the end
    node* delnode = slowp->next;
    slowp->next = slowp->next->next;
    delete delnode;
    return head;
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
    l1.deletemid();
    l1.display();
    l1.DeleteNthnodefromEnd(1);
    l1.display();
}