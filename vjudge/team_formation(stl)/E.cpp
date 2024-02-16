#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    stack<char>st;
    int len = s.length();
    for(int i = 0;i<len;i++){
        if(st.empty()){
            st.push(s[i]);
        }
        else if(s[i]==st.top()){
            st.pop();
        }
        else{
            st.push(s[i]);
        }
    }
    int size = st.size();
    int time = ((len-size)/2);
    if(size==len){
        cout<<"NO"<<endl;
    }
    else if(time%2==0){
        cout<<"NO"<<endl;
    }
    else if(time%2){
        cout<<"YES"<<endl;
    }
}