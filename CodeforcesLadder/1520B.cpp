#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,count=0,mult=1,tot=1;
        cin>>n;
        while(tot<=n){
            for(int i = 1;i<10;i++){
                if(tot>n) break;
                count++;
                tot=tot+mult;
            }
            mult=mult*10+1;
            tot=mult;
        }
        cout<<count<<endl;
    }
}