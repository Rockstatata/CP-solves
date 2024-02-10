#include<bits/stdc++.h>
 
using namespace std;

int countzero(int n){
    int cnt = 0;
    for(int i = 5;n/i >=1;i *=5){
        cnt+=(n/i);
    }
    return cnt;
}

int BS(int n){
    long long L = 0, R = 1000000000;
    while(L<R){
        int M = (L+R)/2;
        if(countzero(M)<n){
            L = M+1;
        }
        else{
            R = M;
        }
    }
    return L;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t,i=1;
    cin>>t;
    while(i<=t){
        long long z,l;
        cin>>z;
        int ans = BS(z);
        if(countzero(ans) == z){
            cout<<"Case "<<i++<<": "<<ans<<endl;
        }
        else{
            cout<<"Case "<<i++<<": impossible"<<endl;
        }
    }   
}