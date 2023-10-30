#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string pi = "3141592653589793238462643383279502884197";
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int len=s.size(),count=0;
        for(int i = 0;i<len;i++){
            if(pi[i]==s[i]){
                count++;
            }
            else{
                break;
            }
        }
        cout<<count<<endl;
    }   
}