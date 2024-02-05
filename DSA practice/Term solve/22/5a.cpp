#include<bits/stdc++.h>
 
using namespace std;

template<class T>
struct node{
    T INFO;
    node* LINK;
};

template<class T>
class Linkedlist{
    node<T>* head;
public:
    Linkedlist(){
        head = NULL;
    }

    void inserthead(const T& value){
        node<T>* newnode = new node<T>;
        newnode->INFO = value;
        newnode->LINK = NULL;
        if(head==NULL){
            head = newnode;
        }
        else{
            newnode->LINK = head;
            head = newnode;
        }
    }

    void inserttail(const T& value){
        node<T>* newnode = new node<T>;
        newnode->INFO = value;
        newnode->LINK = NULL;
        if(head==NULL){
            head = newnode;
        }
        else{
            node<T>* cur = head;
            while(cur->LINK!=NULL){
                cur = cur->LINK;
            }
            cur->LINK = newnode;
        }
    }

    void deletehead(){
        if(head==NULL){
            cout<<"Not possible"<<endl;
            return;
        }
        node<T>* temp = head;
        head = head->LINK;
        delete temp;
        
    }

    void deletetail(){
        if(head==NULL){
            cout<<"Not possible"<<endl;
            return;
        }
        node<T>* cur = head, *prev = NULL;
        while(cur->LINK!=NULL){
            prev = cur;
            cur = cur->LINK;
        }
        prev->LINK = NULL;
        delete cur;
    }


    void deletepos(int k){
        if(k==0){
            deletehead();
        }
        else if(k==get_length()){
            deletetail();
        }
        else{
            if(k<0 || k>get_length()){
                cout<<"Not Possible"<<endl;
            }
            else{
                int count = 0;
                node<T>* cur = head, *prev = NULL;
                while(count!=k){
                    prev = cur;
                    cur = cur->LINK;
                    count++;
                }
                prev->LINK = cur->LINK;
                delete cur;
            }
        }
    }

    int get_length(){
        node<T>* cur = head;
        int size = 0;
        while(cur!=NULL){
            cur=cur->LINK;
            size++;
        }
        return size;
    }

    node<T>* gethead(){
        return head;
    }

    T front(){
        if(head!=NULL)return head->INFO;
    }

    T back(){
        node<T>* cur = head;
        while(cur->LINK!=NULL){
            cur=cur->LINK;
        }
        return cur->INFO;
    }

    void display(){
        node<T>* cur = head;
        while(cur!=NULL){
            cout<<cur->INFO<<" ";
            cur = cur->LINK;
        }
        cout<<endl;
    }

    void rotate(int k){
        if(k<0){
            k = get_length()-((-1)*k);
        }
        while(k){
            T data = back();
            deletetail();
            inserthead(data);
            k--;
        }
    }

    node<T>* _merge(node<T>* first, node<T>* second){
        if(!first){
            return second;
        }
        if(!second){
            return first;
        }
        if(first->INFO < second->INFO){
            first->LINK = _merge(first->LINK,second);
            return first;
        }
        else{
            second->LINK = _merge(first,second->LINK);
            return second;
        }
    }

    void merge(vector<node<T>*>& list1){
        int len = list1.size();
        int i=0;
        while(i<len){
            node<T>* second = list1[i];
            head = _merge(head,second);
            i++;
        }
    }
};

 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Linkedlist<int>l1,l2,l3,l4,l5;
    l1.inserthead(1);
    l1.inserttail(2);
    l1.inserttail(3);
    l1.inserttail(4);
    l1.inserttail(5);
    l1.display();

    l2.inserthead(3);
    l2.inserttail(7);
    l2.inserttail(9);
    l2.inserttail(10);
    l2.display();

    l3.inserthead(2);
    l3.inserttail(5);
    l3.inserttail(6);
    l3.display();

    l4.inserthead(6);
    l4.inserttail(8);
    l4.inserttail(12);
    l4.display();

    vector<node<int>*>list1 {l1.gethead(),l2.gethead(),l3.gethead(),l4.gethead()};
    l5.merge(list1);
    l5.display();

    l5.rotate(2);
    l5.display();
}