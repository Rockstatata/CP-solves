#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,count=0;
        cin>>n;
        int len = ceil(log10(n));
        count+=(9*(len-1));
        n/=pow(10,len-1);
        count+=n;
        cout<<count<<endl;
    }
}