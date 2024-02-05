#include<bits/stdc++.h>
using namespace std;
//define
#define ll long long int
#define ld long double
#define TT int t;cin>>t; for(int tt=1;tt<=t;tt++)
#define LO cout<<"Case "<<tt<<": ";
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define PR(ans) (ans)? cout<<"YES\n":cout<<"NO\n";
//constants
const ll M=1e9+7;
const int N=1e6+3;
//main
int main()
{
    fastio
    TT
    {
        int n;
        cin>>n;
        ll a[n+1];
        for(int i=1;i<n+1;i++)cin>>a[i];
        ll b[n+1];
        for(int i=1;i<n+1;i++){
            if(i%2==1){
                b[i]=-a[i];
            }
            else{
                b[i]=a[i];
            }
        }
        ll pref[n+1];
        pref[0] = 0;
        for(int i = 1;i<n+1;i++){
            pref[i]=pref[i-1]+b[i];
        }
        set<ll>chk;
        bool ans = 0;
        for(auto x:pref){
            if(chk.count(x)){
                ans=1;
            }
            chk.insert(x);
        }
        if(ans){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}

