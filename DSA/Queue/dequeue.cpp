#include<bits/stdc++.h>

using namespace std;

template <class T>
class Node
{
    public:
    T data;
    Node *next;
    Node *prev;
};

template <class T>
class Dequeue {
    Node<T> *head;
    Node<T> *tail;
public:
     void push_front(const T& value){
        Node<T> *n=new Node<T>();
        n->data=value;
        if(head==nullptr){
            head=n;tail=n;
        }
        else{
            n->next=head;
            head->prev=n;
            head=n;
            head->prev=nullptr;
        }
    }

    void push_back(const T& value){
        Node<T> *n=new Node<T>();
        n->data=value;
        if(head==nullptr){
            head=n;tail=n;
            n->next=nullptr;
            n->prev=nullptr;
        }
        else{
            tail->next=n;
            n->prev=tail;
            n->next=nullptr;
            tail=n;
        }
    }
    
    void pop_front()
    {   
        if(this->empty()){
            cout<<"The List Is Empty"<<endl;
            return;
        }
        else{
            Node<T> *n=new Node<T>();
            n=head;
            head=head->next;
            if(head==nullptr){
                tail=nullptr;
            }
            else {
                head->prev=nullptr;
            }
            delete n;}
        }

    void pop_back(){
        if(this->empty()){
            cout<<"The List Is Empty"<<endl;
            return;
        }
        else{
            Node<T> *n=new Node<T>();
            n=tail;
            tail=tail->prev;
            if(tail==nullptr){
                head=nullptr;
            }
            else
                tail->next=NULL;
            delete n;
         }
}
public:
    Dequeue(){
        head=nullptr;
        tail=nullptr;
    }
    ~Dequeue(){
        Node<T> *current=new Node<T>();
        current=head;
        while(current!=nullptr){
            Node<T> *temp=new Node<T>();
            temp=current;
            current=current->next;
            delete temp; 
        } 
    }
    
    bool empty() const
    {
        if(head==tail&&head==nullptr)
        return true;
        return false;
    }

    void display() const{
    if(this->empty())
        {
            cout<<"The List Is Empty"<<endl;
            return;
        }
        else{
            Node<T> *current=new Node<T>();
        current=head;
        while(current!=nullptr)
        {
            cout<<current->data<<" ";
        current=current->next; 
        } 
        cout<<endl;}
    }
int size() const
{
    Node<T> *current=new Node<T>();
    current=head;
    int c=0;
    while(current!=nullptr)
    {
        c++;
        current=current->next; 
    } return c;
}

};

template <class T>
class Queue: public Dequeue<T> {
   
    public:
    Queue() { }
    ~Queue() {}
    void push(const T& value)
    {   
        this->push_back(value);
    }
    void pop()
    {   
        this->pop_front();
    }
    } ;
    
template <class T>
class Stack:public Dequeue<T> {
    public:
    Stack(){}
    ~Stack(){}
  
    void push(const T& value)
    {
      this->push_front(value);
    }
    void pop()
    {   
        this->pop_front();
    }
};


int main(){
    Dequeue<int>d1;
    d1.push_back(1);
    d1.push_front(2);
    d1.display();

    stack<int>s1;

    Queue<int>q1;
    q1.push(1);
    q1.push(2);
    q1.display();
}