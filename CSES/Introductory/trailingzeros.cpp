#include<bits/stdc++.h>
 
using namespace std;

long long zeros(long long n){
    if(n==0) return 0;
    return n/5 + zeros(n/5);
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin>>n;
    long long ans = zeros(n);
    cout<<ans<<endl;
}