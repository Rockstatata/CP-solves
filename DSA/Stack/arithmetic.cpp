#include<bits/stdc++.h>
 
using namespace std;

int prec(char c) {
  if(c=='(' || c==')'){
    return 4;
  }
  else if (c == '^')
    return 3;
  else if (c == '/' || c == '*')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return -1;
}

string infixToPostfix(string s) {
  stack < char > st; //For stack operations, we are using C++ built in stack
  string result;

  for (int i = 0; i < s.length(); i++) {
    char c = s[i];

    // If the scanned character is
    // an operand, add it to output string.
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
      result += c;

    // If the scanned character is an
    // ‘(‘, push it to the stack.
    else if (c == '(')
      st.push('(');

    // If the scanned character is an ‘)’,
    // pop and to output string from the stack
    // until an ‘(‘ is encountered.
    else if (c == ')') {
      while (st.top() != '(') {
        result += st.top();
        st.pop();
      }
      st.pop();
    }

    //If an operator is scanned
    else {
      while (!st.empty() && prec(s[i]) <= prec(st.top())) {
        result += st.top();
        st.pop();
      }
      st.push(c);
    }
  }

  // Pop all the remaining elements from the stack
  while (!st.empty()) {
    result += st.top();
    st.pop();
  }

  cout << "Prefix expression: " << result << endl;
  return result;
}


int postfix_eval(string str)
{
    stack<int> st;
    for(int i=0;i<str.length();i++)
    {
        char x = str[i];
        if(isdigit(x))
        {
            st.push(x - '0');
        }
        else
        {
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();
            switch(x)
            {
                case '+' : st.push(op2 + op1);
                            break;
                case '-' : st.push(op2 - op1);
                            break;
                case '*' : st.push(op2 *  op1);
                            break;
                case '/' : st.push(op2 / op1);
                            break;
            }
            }
        }
        return st.top();
    }

 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s = "((5+3)*7)";
    string result = infixToPostfix(s);
    cout<<postfix_eval(result)<<endl;
}

