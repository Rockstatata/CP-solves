#include <bits/stdc++.h>

using namespace std;

template<class T>
struct node{
    T data;
    node<T>* prev;
    node<T>* next;
};

template<class T>
class Stack{
    node<T>* top;
public:
    Stack(){
        top = NULL;
    }

    void push(const T& data){
        node<T>* newnode = new node<T>;
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
        node<T> *temp = top;
        top = top->next;
        delete temp;
    }

    bool empty(){
        if(top==NULL){
            return true;
        }
        return false;
    }

    T peek(){
        if(!empty()){
            return top->data;
        }
        return -1;
    }

    int size(){
        node<T>* cur = top;
        int size = 0;
        while(cur!=NULL){
            cur= cur->next;
            size++;
        }
        return size;
    }

    void display(){
        int sizet = size();
        node<T>* cur = top;
        while(sizet--){
            cout<<cur->data<<" ";
            cur=cur->next;
        }
        cout<<endl;
    }

    ~Stack(){
        delete top;
    }

};

template<class T>
class Queue{
    node<T> *head, *tail;
public:
    Queue(){
        head=tail=NULL;
    }

    void enqueue(const T& data){
        node<T> *newnode = new node<T>;
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
        node<T> *temp = head;
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

    T front(){
        return head->data;
    }

    T back(){
        return tail->data;
    }

    int size(){
        int sizet = 0;
        if(empty()){
            return 0;
        }
        node<T>* cur = head;
        while(cur!=NULL){
            cur= cur->next;
            sizet++;
        }
        return sizet;
    }

    void display(){
        int sizet = size();
        node<T>* cur = head;
        while(sizet--){
            cout<<cur->data<<" ";
            cur=cur->next;
        }
        cout<<endl;
    }

    ~Queue(){
        delete head;
        delete tail;
    }
};

template<class T>
class Dequeue{
    node<T>* head, *tail;
public:
    Dequeue(){
        head=NULL;
        tail= NULL;
    }

    void push_front(const T& value){
        node<T>* newnode = new node<T>;
        if(newnode==NULL){
            cout<<"DEQUEUE OVERFLOW"<<endl;
            return;
        }
        newnode->data = value;
        newnode->prev = NULL;
        newnode->next = NULL;
        if(head==NULL){
            head = newnode;
            tail = newnode;
        }
        else{
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
    }

    void push_back(const T& value){
        node<T>* newnode = new node<T>;
        if(newnode==NULL){
            cout<<"DEQUEUE OVERFLOW"<<endl;
            return;
        }
        newnode->data = value;
        newnode->prev = NULL;
        newnode->next = NULL;
        if(head==NULL){
            head = newnode;
            tail = newnode;
        }
        else{
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }

    void pop_front(){
        if(head==NULL){
            cout<<"DEQUEUE UNDERFLOW"<<endl;
            return;
        }
        else if(head==tail){
            node<T> *cur = head;
            delete cur;
            head = NULL;
            tail = NULL;
        }
        else{
            node<T> *cur = head;
            head = head->next;
            delete cur;
            head->prev = NULL;
        }
    }
    

    void pop_back(){
        if(head==NULL){
            cout<<"DEQUEUE UNDERFLOW"<<endl;
            return;
        }
        else if(head==tail){
            node<T> *cur = head;
            delete cur;
            head = NULL;
            tail = NULL;
        }
        else{
            node<T> *cur = tail;
            tail= tail->prev;
            delete cur;
            tail->next = NULL;
        }
    }

    T front(){
        if(head!=NULL)return head->data;
        return -1;
    }

    T back(){
        if(head!=NULL)return tail->data;
        return -1;
    }

    bool empty() const{
        if(head==NULL){
            return true;
        }
        return false;
    }

    int size(){
        if(empty()){
            return 0;
        }
        node<T>* cur = head;
        int count = 0;
        while(cur!=NULL){
            cur = cur->next;
            count++;
        }
        return count;
    }

    void display(){
        int len = size();
        node<T>* cur = head;
        while(len--){
            cout<<cur->data<<" ";
            cur = cur->next;
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

string infixtoprefix(string s){
    reverse(s.begin(),s.end());
    int len = s.length();
    for(int i = 0;i<len;i++){
        if(s[i]=='(') s[i]=')';
        else if(s[i]==')') s[i]='(';
        else if(s[i]=='{') s[i]='}';
        else if(s[i]=='}') s[i]='{';
        else if(s[i]=='[') s[i]=']';
        else if(s[i]==']') s[i]='[';
    }
    string p = "";
    Stack<char>st;
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
    reverse(p.begin(),p.end());
    return p;
}


string infixtopostfix(string s){
    string p = "";
    Stack<char> st;
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

template<class T>
T postfixeval(string p){
    stack<T> st;
    for(int i = 0;i<p.length();i++){
        if((p[i]>='a' && p[i]<='z') || (p[i]>='A' && p[i]<='Z') || (p[i]>='0' && p[i]<='9')){
            st.push(p[i]-'0');
        }
        else{
            T op1 = st.top();
            st.pop();
            T op2 = st.top();
            st.pop();
            switch(p[i]){
                case '+': st.push(op2+op1); break;
                case '-': st.push(op2-op1); break;
                case '*': st.push(op2*op1); break;
                case '/': st.push(op2/op1); break;
            }
        }
    }
    return st.top();
}

template<class T>
T prefixeval(string p){
    stack<T> st;
    for(int i = p.length()-1;i>=0;i--){
        if((p[i]>='a' && p[i]<='z') || (p[i]>='A' && p[i]<='Z') || (p[i]>='0' && p[i]<='9')){
            st.push(p[i]-'0');
        }
        else{
            T op1 = st.top();
            st.pop();
            T op2 = st.top();
            st.pop();
            switch(p[i]){
                case '+': st.push(op1+op2); break;
                case '-': st.push(op1-op2); break;
                case '*': st.push(op1*op2); break;
                case '/': st.push(op1/op2); break;
            }
        }
    }
    return st.top();
}

string reverseparenthesis(string str){
    int len = str.length();
    Stack<int> st;
 
    for (int i = 0; i < len; i++) {
 
        // Push the index of the current
        // opening bracket
        if (str[i] == '(') {
            st.push(i);
        }
 
        // Reverse the substring starting
        // after the last encountered opening
        // bracket till the current character
        else if (str[i] == ')') {
            reverse(str.begin() + st.peek(),
                    str.begin() + i+ 1);
            st.pop();
        }
    }   
 
    // To store the modified string
    string res = "";
    int flag = 0,count=0;
    for (int i = 0; i < len; i++) {
        res += (str[i]);
    }
    return res;
}

int main()
{
    Stack<int> s;
    Queue<int> q;
    Dequeue<int> d;

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
    cout<<endl;

    d.push_front(1);
    d.push_back(2);
    cout<<d.size()<<endl;
    cout<<d.front()<<endl;
    cout<<d.back()<<endl;
    d.display();

    d.pop_back();
    d.display();

    d.pop_front();
    cout<<d.size()<<endl;
    cout<<endl;

    string sti = "((2+3)*1+(2/1))";
    string rev = "((abcx(def)ghi)xyz)";

    cout<<infixtopostfix(sti)<<endl;
    cout<<infixtoprefix(sti)<<endl;
    cout<<postfixeval<int>(infixtopostfix(sti))<<endl;
    cout<<prefixeval<int>(infixtoprefix(sti))<<endl;

    cout<<reverseparenthesis(rev)<<endl;

    return 0;
}
