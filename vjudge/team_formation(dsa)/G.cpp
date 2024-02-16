#include<bits/stdc++.h>
 
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,t;
    cin>>n>>t;
    ll machines[n];
    for(ll i=  0;i<n;i++){
        cin>>machines[i];
    }
    ll i = 0,j=1e18;
    ll ans = 1e18;
    while(i<=j){
        ll mid = (i+j)/2;
        ll products = 0;
        for(int i= 0;i<n;i++){
            products+=min((mid/machines[i]),(ll)1e9);
        }
        if(products>=t){
            if(mid<ans){
                ans = mid;
            }
            j = mid-1;
        }
        else{
            i = mid+1;
        }
    }
    cout<<ans<<endl;
}