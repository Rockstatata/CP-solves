#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    if(n<=3 && n!=1) cout<<"NO SOLUTION"<<endl;
    else if(n==1) cout<<1<<endl;
    else{
        if(n%2==0){
            int i = 2;
            for(i;i<=n;i+=2){
                cout<<i<<" ";
            }
            i = 1;
            for(i;i<=n;i+=2){
                cout<<i<<" ";
            }
        }
        else{
            int i = 1;
            for(i;i<=n;i+=2){
                cout<<i<<" ";
            }
            i = 2;
            for(i;i<=n;i+=2){
                cout<<i<<" ";
            }
        }
    }
}