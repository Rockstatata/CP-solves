#include<bits/stdc++.h>
 
using namespace std;

template<class T>
struct node{
    T data;
    node<T>* next;
    node<T>* prev;
};

template<class T>
class doublylinkedlist{
    node<T> *head;
    node<T> *tail;

public:
    doublylinkedlist(){
        head = NULL;
        tail = NULL;
    }

    void insertBegin(const T& value){
        node<T>* newnode = new node<T>;
        newnode->data = value;
        newnode->next = NULL;
        newnode->prev = NULL;
        if(head==NULL){
            head = newnode;
            tail = newnode;
        }
        else{
            head->prev=newnode;
            newnode->next = head;
            head = newnode;
        }
    }

    void insertEnd(const T& value){
        node<T>* newnode = new node<T>;
        newnode->data = value;
        newnode->next = NULL;
        newnode->prev = NULL;
        if(head==NULL){
            head = newnode;
            tail = newnode;
        }
        else{
            tail->next = newnode;
            newnode->prev = tail;
            newnode->next = NULL;
            tail = newnode;
        }
    }

    void insertAtPosition(int pos,const T& value){
        node<T>* newnode = new node<T>;
        newnode->data = value;
        newnode->next = NULL;
        newnode->prev = NULL;
        int count = 0, length= getLength();
        if(pos>length || pos<0){
            cout<<"OUT OF BOUNDS ERROR"<<endl;
        }
        else{
            node<T>* cur = head;
            while(cur!=NULL && count!=pos){
                cur=cur->next;
                count++;
            }
            if(pos==length){
                insertEnd(value);
            }
            else if(pos==0){
                insertBegin(value);
            }
            else{
                newnode->next = cur;
                newnode->prev = cur->prev;
                cur->prev->next = newnode;
                cur->prev = newnode;
            }
        }  
    }

    void deletebegin(){
        if(head==NULL){
            cout<<"Cannot Delete element from an empty list"<<endl;
            return;
        }
        else{
            node<T>* cur = head;
            head=head->next;
            head->prev = NULL;
            delete cur;
        }
    }

    void deleteEnd(){
        if(head==NULL){
            cout<<"Cannot Delete element from an empty list"<<endl;
            return;
        }
        else{
            node<T>* cur = head;
            while(cur->next!=NULL){
                cur = cur->next;
            }
            cur->prev->next = NULL;
            tail = cur->prev;
            delete cur;
        }
    }

    void deleteatposition(int pos){
        int count = 0, length= getLength();
        if(pos>length || pos<0){
            cout<<"OUT OF BOUNDS ERROR"<<endl;
        }
        else{
            node<T>* cur = head;
            while(cur!=NULL && count!=pos){
                cur=cur->next;
                count++;
            }
            if(pos==length){
                deleteEnd();
            }
            else if(pos==0){
                deletebegin();
            }
            else{
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
                delete cur;
            }
        } 
    }

    void deletebyvalue(int value){
        int length = getLength(),count=0,flag=0;
        node<T>* cur = head;
        while(cur!=NULL){
            if(cur->data==value){
                node<T>* temp = cur->next;
                deleteatposition(count);
                count--;
                cur = temp;
                flag=1;
            }
            if(flag==0)cur=cur->next;
            count++;
            flag=0;
        }
    }

    void swap ( int* a, int* b ) { 
        int t = *a; 
        *a = *b; 
        *b = t; 
    }

    node<T>* partition(node<T> *l, node<T> *h) {  
        int x = h->data; 
        node<T> *i = l->prev; 
        for (node<T> *j = l; j != h; j = j->next) 
        { 
            if (j->data <= x) 
            { 
                i = (i == NULL)? l : i->next; 
                swap(&(i->data), &(j->data)); 
            } 
        } 
        i = (i == NULL)? l : i->next; 
        swap(&(i->data), &(h->data)); 
        return i; 
    } 
 
    void _quickSort(node<T>* l, node<T> *h) { 
        if (h != NULL && l != h && l != h->next) 
        { 
            node<T> *p = partition(l, h); 
            _quickSort(l, p->prev); 
            _quickSort(p->next, h); 
        } 
    } 
 
    void quickSort() { 
        node<T> *h = tail; 
        _quickSort(head, h); 
    } 

    node<T> *split(node <T> *cur) { 
        node<T> *fast = cur,*slow = cur; 
        while (fast->next && fast->next->next) 
        { 
            fast = fast->next->next; 
            slow = slow->next; 
        } 
        node<T> *temp = slow->next; 
        slow->next = NULL; 
        return temp; 
    }

    node<T> *merge(node<T> *first, node<T> *second){ 
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
    
    node<T> *mergeSort(node<T> *cur) { 
        if (!cur || !cur->next) 
            return cur; 
        node<T> *second = split(cur); 
        
        cur = mergeSort(cur); 
        second = mergeSort(second); 
        
        return head = merge(cur,second); 
    } 

    void display(){
        node<T>* cur = head;
        while(cur!=NULL){
            cout<<cur->data<<" ";
            cur = cur->next;
        }
        cout<<endl;
    }
    int getLength(){
        int count = 0;
        node<T>* cur = head;
        while(cur!=NULL){
            cur=cur->next;
            count++;
        }
        return count;
    }

    node<T>* gethead(){
        return head;
    }

//     void swapNodes(Node** head_ref, int x, int y)
// {
//     // Nothing to do if x and y are same
//     if (x == y)
//         return;
 
//     // Search for x (keep track of prevX and CurrX
//     Node *prevX = NULL, *currX = *head_ref;
//     while (currX && currX->data != x) {
//         prevX = currX;
//         currX = currX->next;
//     }
 
//     // Search for y (keep track of prevY and CurrY
//     Node *prevY = NULL, *currY = *head_ref;
//     while (currY && currY->data != y) {
//         prevY = currY;
//         currY = currY->next;
//     }
 
//     // If either x or y is not present, nothing to do
//     if (currX == NULL || currY == NULL)
//         return;
 
//     // If x is not head of linked list
//     if (prevX != NULL)
//         prevX->next = currY;
//     else // Else make y as new head
//         *head_ref = currY;
 
//     // If y is not head of linked list
//     if (prevY != NULL)
//         prevY->next = currX;
//     else // Else make x as new head
//         *head_ref = currX;
 
//     // Swap next pointers
//     Node* temp = currY->next;
//     currY->next = currX->next;
//     currX->next = temp;

    void swapkthnode(int k){
        node<T> *cur1 = head, *cur2 = tail;
        while(--k){
            cur1 = cur1->next;
            cur2 = cur2->prev;
        }
        node<T> *prev1 = cur1->prev, *prev2 = cur2->prev;
        node<T> *next1 = cur1->next, *next2 = cur2->prev;
        if(prev1!=NULL){
            prev1->next = cur2;
        }
        else{
            head = cur2;
        }

        if(next1!=NULL){
            next1->prev = cur2;
        }
        else{
            tail = cur2;
        }

        if(prev2!=NULL){
            prev2->next = cur1;
        }
        else{
            head = cur1;
        }

        if(next2!=NULL){
            next2->prev = cur1;
        }
        else{
            tail = cur1;
        }

        node<T>* temp = cur2->next;
        cur2->next = cur1->next;
        cur1->next = temp;

        node<T>* temp2 = cur2->prev;
        cur2->prev = cur1->prev;
        cur1->prev = temp2;

    }

};

int main(){
    doublylinkedlist<int>l1;
    l1.insertEnd(1);
    l1.insertEnd(2);
    l1.insertEnd(3);
    l1.insertEnd(4);
    l1.insertEnd(5);
    l1.display();
    l1.swapkthnode(1);
    l1.display();
}