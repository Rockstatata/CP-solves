#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int cnta=0,cntb=0;
        string s;
        cin>>s;
        for(int i=0;i<s.size();i++){
            if(s[i]=='A'){
                cnta++;
            }
            else{
                cntb++;
            }
        }
        cout<<((cnta>cntb)?"A":"B")<<endl;
    }
}