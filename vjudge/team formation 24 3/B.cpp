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
 

ll maxsum(ll i,vector<int>apples,ll size,ll k){
    vector<int>dp ={0,INT_MIN,INT_MIN};

    for(auto i: apples){
        vector<int> tmp(3);
        cout<<i<<endl;
        for(int j=0;j<3;j++){
            cout<<j<<endl;
            cout<<dp[(j+i)%3]<<" "<<dp[j]+i<<endl;
            tmp[(j+i)%3] = max(dp[(j+i)%3],dp[j]+i);
            cout<<tmp[(j+i)%3]<<endl;
        }
        cout<<endl;
        dp = tmp;
    }

    return dp[0];
}

void solve(){
    ll n,sum=0,x;
    cin>>n;
    vector<int>apples;
    for(int i = 0;i<n;i++){
        cin>>x;
        apples.push_back(x);
    }
    sort(apples.begin(),apples.end());
    ll i = 0,k=0;
    ll maxi = maxsum(0,apples,n,0);
    cout<<maxi<<endl;
}
int main()
{
 fast_cin();
 ll t=1;
 //cin >> t;
 for(int it=1;it<=t;it++) {
    //cout << "Case #" << it+1 << ": ";
     solve();
 }
 return 0;
}