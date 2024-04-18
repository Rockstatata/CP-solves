#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n,moves=0,attack=0;
    cin>>n;
    for(long long i = 1;i<=n;i++){
        moves = (((i*i)-1)*(i*i))/2;
        attack = 4 * (i-1) * (i-2);
        cout<<moves-attack<<endl;
    }
}