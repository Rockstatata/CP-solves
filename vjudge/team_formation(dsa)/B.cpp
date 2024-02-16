#include<bits/stdc++.h>
 
using namespace std;

typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,k,m;
    cin>>n>>k>>m;
    vector<ll>num;
    ll x;
    for(int i = 0;i<n;i++){
        cin>>x;
        num.push_back(x);
    }
    vector<ll>ans;
    for(int i = 1;i<n;i++){
        ll y = num[i]-num[i-1];
        if(y==0){
            ans.push_back(num[i]);
        }
        else if(y%m==0){
            ans.push_back(num[i]);
            ans.push_back(num[i-1]);
        }
    }
    sort(ans.begin(),ans.end());
    if(ans.size()>=k){
        cout<<"Yes"<<endl;
        for(int i = 0;i<k;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}