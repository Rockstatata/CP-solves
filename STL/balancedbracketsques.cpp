#include<bits/stdc++.h>
 
using namespace std;

unordered_map<char,int>symbols={{'[',-1},{'{',-2},{'(',-3},{']',1},{'}',2},{')',3}};
string isBalanced(string s){
    stack<char>st;
    for(char bracket:s){
        if(symbols[bracket]<0){
            st.push(bracket);
        }
        else{
            if(st.empty())return "NO";
            char top=st.top();
            st.pop();
            if(symbols[top]+symbols[bracket]){
                return "NO";
            }
        }
    }
    if(st.empty()) return "YES";
    return "NO";
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<isBalanced(s)<<endl;
    }
}