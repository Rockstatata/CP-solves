#include<bits/stdc++.h>
 
using namespace std;

int prec(char c) {
  if (c == '^')
    return 3;
  else if (c == '/' || c == '*')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return -1;
}


template<class T>
struct Node{
    T data;
    Node<T>* next;
};

template<class T>
class Stack{
    Node<T> *top;
public:
    Stack(){
        top = NULL;
    }

    void push(T data){
        Node<T> *newnode = new Node<T>();
        newnode->data = data;
        if(top==NULL){
            newnode->next=NULL;
        }
        else{
            newnode->next=top;
        }
        top = newnode;
    }

    void pop(){
        Node<T>* temp;
        if(top==NULL){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        temp = top;
        top = top->next;
        delete temp;
    }

    T peek(){
        if(top==NULL){
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        return top->data;
    }

    void display(){
        Node<T>* temp;
        if(top == NULL){
            cout<<"Stack Underflow\n"<<endl;
        }
        else{
            temp = top;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
    }

    int empty(){
        if(top==NULL){
            return 0;
        }
        else{
            return 1;
        }
    }

    void infixtoPostfix(string s){
        string result;
        int len = s.length();

        for(int i = 0;i<len;i++){
            char c = s[i];

            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
                result += c;

            else if(c=='('){
                push(c);
            }

            else if(c==')'){
                while(top() != '('){
                    result+=top();
                    pop();
                }
                pop(); 
            }

            else{
                while(!empty() && prec(s[i]) <= prec(top())){
                    result+=top();
                    pop();
                }
                push(c);
            }
        }

        while(!empty()){
            result+=top();
            pop();
        }
        
        cout<<"Prefix expression: "<<result<<endl;
    }

};
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Stack<char> stk;
    // stk.push(1);
    // stk.push(2);
    // stk.push(3);
    // stk.display();
    // stk.pop();
    // int top_value = stk.peek();
    // if(top_value!=-1){
    //     cout<<"Top Value is: "<<top_value<<endl;
    // }
    // cout<<"Element after the pop operation:"<<endl;
    // stk.display();

    string exp = "(p+q)*(m-n)";
    cout << "Infix expression: " << exp << endl;
    stk.infixtoPostfix(exp);
    return 0;
}