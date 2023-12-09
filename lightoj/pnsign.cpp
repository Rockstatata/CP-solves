#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,cm=-1,x=1;
        cin>>n>>m;
        for(int i = 1;i<=n;i++){
            x=(i*cm);
            cout<<x<<" ";
            if(i%m==0){
                cm*=-1;
            }
        }
        cout<<endl;
    }   
}