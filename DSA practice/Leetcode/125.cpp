#include<bits/stdc++.h>
 
using namespace std;

bool ispalindrome(string s){
    int len = s.length();
    stack<char>st,ts;
    for(auto &ch:s){
        st.push(char(tolower(ch)));
    }
    reverse(s.begin(),s.end());
    for(auto &ch:s){
        ts.push(char(tolower(ch)));
    }
    int count = 0;
    while(count<(len/2)){
        if(st.empty() || ts.empty()){
            break;
        }
        if((iswalnum(st.top())) && (iswalnum(ts.top()))){
            if(st.top()!=ts.top()){
                return false;
            }
            st.pop();
            ts.pop();
            count++;
            continue;
        }
        if(!(iswalnum(st.top()))){
            st.pop();
        }
        if(!(iswalnum(ts.top()))){
            ts.pop();
        }
    }
    return true;
}


 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    getline(cin,s);
    cout<<ispalindrome(s)<<endl;
}