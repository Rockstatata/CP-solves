#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    int len = s.length();
    int v = 0,h = 0;
    for(int i = 0 ;i<len;i++){
        if(s[i]=='0'){
            cout<<2<<" "<<v+1<<endl;
            v = (v+1)%4;
        }
        else{
            cout<<1<<" "<<h+1<<endl;
            h = (h+2)%4;
        }
    }    
}