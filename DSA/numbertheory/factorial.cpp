#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,M=47,fact=0;
    cin>>n;
    for(int i = 2;i<=n;i++){
        fact=(fact%i)%M;
    }
}