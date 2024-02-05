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

    node *split(node  *cur) { 
        node *fast = cur,*slow = cur; 
        while (fast->next && fast->next->next) 
        { 
            fast = fast->next->next; 
            slow = slow->next; 
        } 
        node *temp = slow->next; 
        slow->next = NULL; 
        return temp; 
    }

    node*merge(node *first, node *second){ 
        if (!first) 
            return second; 
    
        if (!second) 
            return first; 
    
        if (first->data < second->data) 
        { 
            first->next = merge(first->next,second); 
            first->next->prev = first; 
            first->prev = NULL; 
            return first; 
        } 

        else
        { 
            second->next = merge(first,second->next); 
            second->next->prev = second; 
            second->prev = NULL; 
            return second; 
        } 
    } 
    
    node *mergeSort(node *cur) { 
        if (!cur || !cur->next) 
            return cur; 
        node *second = split(cur); 
     
        cur = mergeSort(cur); 
        second = mergeSort(second); 
     
        return head = merge(cur,second); 
    }

    void deleteatposition(int pos){
        if(pos==0){
            node *cur = head;
            head = head->next;
            head->prev = NULL;
            delete cur;
        }

        else if(pos==length()){
            node *cur = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete cur;
        }

        else{
            int count = 0;
            node *cur = head;
            while(cur!=NULL && count!=pos){
                count++;
                cur=cur->next;
            }
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            delete cur;
        }
    }

    void removedup(){
        node *cur = head, *temp = cur;
        int pos=1;
        while(cur!=tail){
            if(cur->data != cur->next->data){
                cur= cur->next;
                pos++;
            }
            else{
                deleteatposition(pos);
            }
        }
    }

    int length(){
        node*cur = head;
        int count = 0;
        while(cur!=NULL){
            count++;
            cur = cur->next;
        }
        return count;
    }

    bool twopointertwosum(int k){
        node* first = head, *last = tail;
        while(first!=last){
            int res = first->data+last->data;
            if(res==k){
                return true;
            }
            else if(res>k){
                last = last->prev;
            }
            else{
                first= first->next;
            } 
        }
        return false;
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

    node* gethead(){
        return head;
    }
};
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    linkedlist l1;
    l1.insert(1);
    l1.insert(1);
    l1.insert(1);
    l1.insert(2);
    l1.insert(2);
    l1.insert(5);
    l1.insert(6);
    l1.display();
    l1.removedup();
    l1.display();
}
