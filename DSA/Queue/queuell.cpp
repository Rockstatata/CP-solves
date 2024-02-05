#include<bits/stdc++.h>
 
using namespace std;

template<class T>
struct Node{
    T data;
    Node<T>*next;
};

template<class T>
class Queue{
    Node<T> *front,*rear;
public:
    Queue(){
        front = rear = NULL;
    }

    void enqueue(T data){
        Node<T>* newnode = new Node<T>;
        newnode->data = data;
        newnode->next = NULL;
        if(front == NULL){
            front = rear = newnode;
        }
        else{
            rear->next = newnode;
            rear = newnode;
        }
        cout<<data<<" Element inserted"<<endl;
    }

    void dequeue(){
        if(front == NULL){
            cout<<"Queue underflow"<<endl;
        }

        Node<T>* temp = front;
        if(front == rear){
            front = rear = NULL;
        }
        else{
            front = front->next;
        }
        cout<<temp->data<<" Element deleted"<<endl;
        delete temp;
    }

    void display(){
        if(front==NULL){
            cout<<"Queue Underflow"<<endl;
            return;
        }
        Node<T> *temp = front;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

};
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.dequeue();
    q.dequeue();
    q.display();
    return 0;
}