#include <bits/stdc++.h> 
#include <chrono>
#include <random>
#include <iostream>
#include <cmath>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 

ll solve(){
    ll n;
    cin>>n;
    v64 A,B;
    ll x;
    for(int i = 0;i<n;i++){
        cin>>x;
        A.pb(x);
    }
    for(int i = 0;i<n;i++){
        cin>>x;
        B.pb(x);
    }
    vv32 ans;
    for(int i = 0;i<n;i++){
        v32 mini;
        ll count = 0;
        bool gap = false, firstl= false;
        for(int j=i,k=0;j<A.size() && k<A.size();){        
            if(A[j]==B[k]){
                mini.pb(B[k]);
                if(k==0 || k==n-1) firstl = true;
                j++,k++;
                if(gap==true)count++;
                gap = false;
            }

            else if(A[j]!=B[k]){
                k++;
                gap = true;
            }
        }
        if(count<=1 && firstl)ans.pb(mini);
    }
    ll len = ans.size();
    ll size = 0, max = 0;
    for(int i=  0;i<len;i++){
        size = ans[i].size();
        if(size>=max){
            max = size;
        }
    }

    return n-max;
}
int main()
{
 fast_cin();
 ll t=1;
 cin >> t;
 for(int it=1;it<=t;it++) {
     ll ans = solve();
     cout<<"Case "<<it<<": "<<ans<<endl;
 }
 return 0;
}