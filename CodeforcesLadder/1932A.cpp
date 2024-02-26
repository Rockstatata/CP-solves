#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int i = 0;
        for(i;i<n-1;i++){
            if(s[i]==s[i+1] && s[i]=='*'){
                break;
            }
        }
        int count=0;
        for(i;i>=0;i--){
            if(s[i]=='@'){
                count++;
            }
        }
        cout<<count<<endl;
    }   
}