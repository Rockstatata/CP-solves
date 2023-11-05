#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        long long int moves=0,n,area,co;
        cin>>n;
        area = n/2;
        co=8;
        for(long long int i = 1;i<=area;i++){
            moves+=8*i*i;
        }
        cout<<moves<<endl;
    }
}