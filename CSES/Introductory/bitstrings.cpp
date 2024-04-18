#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin>>n;
    long long mod = 1e9+7,ans=1;
    for(int i = 1;i<=n;i++){
        ans = (ans*2) % mod;
    }
    cout<<ans<<endl;
}