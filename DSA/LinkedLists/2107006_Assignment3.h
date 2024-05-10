#pragma once 

// 2107006 - Sarwad Hasan Siddiqui
// Assignment - 3: Linked List Class Making

#include<bits/stdc++.h>

using namespace std;

template <typename T>
struct Node
{
    T data;
    Node *next;
};

template <typename T>
class linkedList
{
private:
    Node<T> *head;

public:
    linkedList() : head(nullptr) {}

    ~linkedList()
    {
        while (head)
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertFront(const T &value)
    {
        Node<T> *temp = new Node<T>;
        temp->data = value;
        temp->next = nullptr;
        temp->next = head;
        head = temp;
    }

    void insertBack(const T &value)
    {
        Node<T> *curr = new Node<T>;
        curr->data = value;
        curr->next = nullptr; 

        if (head == NULL)
        {
            head = curr;
            return;
            
        }
        Node<T> *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = curr;
    }

    void insertAtPosition(const T &value, int position)
    {

        if (head == NULL)
        {
            if (position == 1)
            {
                insertFront(value);
            }
            else{
                cout<<"Position is out of bounds"<<endl;
            }
        }
        Node<T> *temp = head;
        Node<T> *curr = new Node<T>;
        curr->data = value;
        curr->next = nullptr;

        int cnt{0};
        while (temp)
        {
            cnt++;
            if (cnt == (position - 1))
            {
                curr->next = temp->next;
                temp->next = curr;
                break;
            }
            temp = temp->next;
        }
    }

    bool Search(const T &value) const
    {
        Node<T> *temp = head;
        while (temp)
        {
            if (temp->data == value)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void deletion(int pos){
        if(pos==1){
            if(head==NULL){
                cout<<"Invalid operation"<<endl;
            }
            else{
                Node<T> *temp = head;
                head = head->next;
                delete temp;
            }
        }
        else{
            if(head==NULL){
                cout<<"Invalid operation"<<endl;
            }
            int cnt{0};
            Node<T> *curr = head , *prev = head;
            while(curr!=NULL){
                cnt++;
                if(cnt == (pos)){
                    prev->next = curr->next;
                    delete curr;
                    break;
                }
                prev = curr;
                curr=curr->next;
            }
        }
    }

    void display() const
    {
        Node<T> *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int getLength() const
    {
        int length{0};
        Node<T> *temp = head;
        while (temp)
        {
            length++;
            temp = temp->next;
        }
        return length;
    }
};
