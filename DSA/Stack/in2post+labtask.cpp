#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node* next;
};

class Stack{
    node* top;
public:
    Stack(){
        top = NULL;
    }

    void push(int data){
        node* newnode = new node;
        if(newnode==NULL){
            cout<<"STACK OVERFLOW"<<endl;
            return;
        }
        newnode->data= data;
        if(top==NULL){
            top = newnode;
            top->next = NULL;
        }
        else{
            newnode->next = top;
            top = newnode;
        }
    }

    void pop(){
        if(top==NULL){
            cout<<"STACK UNDERFLOW"<<endl;
            return;
        }
        node *temp = top;
        top = top->next;
        delete temp;
    }

    bool empty(){
        if(top==NULL){
            return true;
        }
        return false;
    }

    int peek(){
        if(!empty()){
            return top->data;
        }
        return -1;
    }

    int size(){
        node* cur = top;
        int size = 0;
        while(cur!=NULL){
            cur= cur->next;
            size++;
        }
        return size;
    }

    void display(){
        int sizet = size();
        node* cur = top;
        while(sizet--){
            cout<<cur->data<<" ";
            cur=cur->next;
        }
        cout<<endl;

    }

};

class Queue{
    node *head, *tail;
public:
    Queue(){
        head=tail=NULL;
    }

    void enqueue(int data){
        node *newnode = new node;
        if(newnode==NULL){
            cout<<"QUEUE OVERFLOW"<<endl;
            return;
        }
        newnode->data = data;
        if(head == NULL){
            head = newnode;
            tail = newnode;
            tail->next = NULL;
        }
        else{
            tail->next = newnode;
            tail = newnode;
            newnode->next = NULL;
        }
    }

    void dequeue(){
        if(head==NULL){
            cout<<"QUEUE UNDERFLOW"<<endl;
            return;
        }
        node *temp = head;
        head = head->next;
        if(head==NULL){
            tail = NULL;
        }
        delete temp;
    }

    bool empty(){
        if(head==NULL){
            return true;
        }
        return false;
    }

    int front(){
        return head->data;
    }

    int back(){
        return tail->data;
    }

    int size(){
        int sizet = 0;
        if(empty()){
            return 0;
        }
        node* cur = head;
        while(cur!=NULL){
            cur= cur->next;
            sizet++;
        }
        return sizet;
    }

    void display(){
        int sizet = size();
        node* cur = head;
        while(sizet--){
            cout<<cur->data<<" ";
            cur=cur->next;
        }
        cout<<endl;
    }
};

int precedence(char c){
    if(c=='*' || c=='/'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    else return 0;
}


string infixtopostfix(string s){
    string p = "";
    Stack st;
    int len = s.length();
    for(int i = 0;i<len;i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')){
            p+=s[i];
        }
        else{
            if(s[i]=='('){
                st.push(s[i]);
            }
            else if((s[i]=='+') || (s[i]=='-') || (s[i]=='/') || (s[i]=='*')){
                if((precedence(s[i])) > (precedence(st.peek()))){
                    st.push(s[i]);
                }
                else{
                    while(!st.empty()){
                        if(st.peek()=='('){
                            st.push(s[i]);
                            break;
                        }
                        else if((precedence(s[i])) < (precedence(st.peek()))){
                                p+=st.peek();
                                st.pop();
                        }
                        else{
                            st.push(s[i]);
                            break;
                        }
                    }
                }
            }
            else if(s[i]==')'){
                while(!st.empty()){
                    if(st.peek()!='('){
                        p+=st.peek();
                        st.pop();
                    }
                    else{
                        st.pop();
                        break;
                    }
                }

            }
        }
    }
    while(!st.empty()){
        p+=st.peek();
        st.pop();
    }
    return p;
}

int main()
{
    Stack s;
    Queue q;

    s.push(1);
    s.push(2);
    cout<<s.size()<<endl;
    cout<<s.peek()<<endl;
    s.display();

    s.pop();
    s.display();

    s.pop();
    cout<<s.size()<<endl;
    cout<<endl;

    q.enqueue(1);
    q.enqueue(2);
    cout<<q.size()<<endl;
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    q.display();

    q.dequeue();
    q.display();

    q.dequeue();
    cout<<q.size()<<endl;


    string sti = "((a+b)*c+(d/e))";
    cout<<infixtopostfix(sti)<<endl;

    return 0;
}
