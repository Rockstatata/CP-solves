#include<bits/stdc++.h>
 
using namespace std;

class Node{
    int roll;
    int marks;
    Node *next;
    friend class Linked_list;
public:
    Node():
        roll{0},marks{0}
    {

    }

    Node(int roll, int marks):
        roll{roll},marks{marks}
    {

    }

    void display(){
        cout<<"ROLL: "<<roll<<endl;
        cout<<"MARKS: "<<marks<<endl;
    }


};

class Linked_list{
    Node *head,*tail;
    friend class Node;
public:
    Linked_list():
        head{NULL},tail{NULL}
    {

    }

    void inserthead(int roll,int marks){
        Node *newnode = new Node(roll,marks);
        if(head==NULL){
            head = newnode;
            tail = head;
            newnode->next = NULL;
            return;
        }
        else{
            newnode->next = head;
            head = newnode;
            return;
        }
    }

    void inserttail(int roll,int marks){
        Node *newnode = new Node(roll,marks);
        if(head==NULL){
            head = newnode;
            tail = head;
            return;
        }
        else{
            tail->next = newnode;
            tail = newnode;
            tail->next=NULL;
            return;
        }
    }
    

    void insert(int roll,int marks){
        Node *newnode = new Node(roll,marks);
        if(head==NULL){
            inserthead(roll,marks);
        }
        else{
            Node *current = head;
            Node *previous = NULL;
            while(current!=NULL){
                if(current->marks > newnode->marks){
                    if(current == head){
                        inserthead(roll,marks);
                    }
                    else{
                        previous->next = newnode;
                        newnode->next = current;                      
                    }
                    tail->next=NULL;
                    return;
                }
                else if(current->marks == newnode->marks){
                    if(current==tail){
                        tail->next = newnode;
                        tail = newnode;
                        tail->next=NULL;
                        return;
                    }
                    if(current->roll>newnode->marks){
                        previous->next = newnode;
                        newnode->next = current;
                    }
                    else{
                        newnode->next = current->next;
                        current->next = newnode;
                    }
                    tail->next=NULL;
                    return;
                }
                previous=current;
                current=current->next;
            }
            tail->next = newnode;
            tail = newnode;
            tail->next = NULL;
            return;  
        }
    }

    void merge(Linked_list list,Linked_list list2){
        Node *current1= list.head;
        Node *current2= list2.head;
        int steps=0;
        while(current1!= NULL || current2!=NULL){
            steps++;
            if(steps%2==1){
                if(current1==NULL)continue;
                inserttail(current1->roll,current1->marks);
                current1=current1->next;
            }
            else{
                if(current2==NULL)continue;
                inserttail(current2->roll,current2->marks);
                current2=current2->next;
            }
        }
    }

    void displayList(){
        Node *current = head;
        while(current!=NULL){
            current->display();
            current=current->next;
        }
    }

    void reverse(){
        Node *current = head, *prev = NULL, *next = NULL;
        while(current!=NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        tail = head;
        head = prev;
    }

    void rotate(int k){
        Node *current = head;
        while(k--){
            tail->next = current;
            tail = current;
            current=current->next;
        }
        head = current;
        tail->next = NULL;
    }

    int getlength(){
        Node* current = head;
        int len = 1;
        while(current!=NULL){
            len++;
            current = current->next;
        }
        return len;
    }

    Node* middlenode(){
        Node* slow = head, *fast = head;
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
    Linked_list list,list2,list3;
    // list.insert(4,95);
    // list.insert(2,85);
    // list.insert(3,90);
    // list.insert(6,33);
    // list.insert(7,88);
    // list.insert(8,93);
    // list.insert(9,0);
    // list.insert(10,84);
    // list.insert(11,85);
    // list.insert(1,80);
    list.insert(1,1);
    list.insert(2,2);
    list.insert(3,3);
    list.insert(4,4);
    list.displayList();
    cout<<endl;
    list2.insert(5,5);
    list2.insert(6,6);
    list2.insert(7,7);
    //list2.insert(8,8);
    // list2.insert(7,88);
    // list2.insert(8,93);
    // list2.insert(9,0);
    // list2.insert(10,84);
    // list2.insert(11,85);
    // list2.insert(1,80);
    list2.displayList();
    cout<<endl;
    list3.merge(list,list2);
    list3.displayList();
    cout<<endl;
    list3.reverse();
    list3.displayList();
    cout<<endl;
    list3.rotate(3);
    list3.displayList();
    cout<<endl;
    return 0;
}