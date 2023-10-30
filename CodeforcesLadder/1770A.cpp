#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    int n,m;
    while(t--){
        cin>>n>>m;
        long long int wb[n+m],sum = 0;
        for(int i = 0;i<n+m;i++){
            cin>>wb[i];
        }
        sort(wb,wb+m+n-1);
        reverse(wb,wb+m+n);
        for(int i = 0;i<n;i++){
            sum+=wb[i];
        }
        cout<<sum<<endl;
    }   
}
