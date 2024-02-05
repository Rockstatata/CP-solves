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
 

void solve(){
    int n,x,y;
    cin>>n;
    vector<pair<ll,ll>>v;
    ll ans[n],sum[n];
    for(int i = 0;i<n;i++){
        cin>>x;
        y=i;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end());
    ll tem=0;
        for(int i=0;i<n;i++)
        {
            sum[i]=v[i].first+tem;
            tem=sum[i];
        }
        auto it=v[n-1];
        int ind=it.second;
        ans[ind]=n-1;
        tem=it.first;
        for(int i=n-2;i>=0;i--)
        {
            if(sum[i]>=v[i+1].first)
            {
                ans[v[i].second]=ans[v[i+1].second];
            }else
            {
                ans[v[i].second]=i;
            }
        }
        for(int i=0;i<n;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
}
int main()
{
 fast_cin();
 ll t=1;
 cin >> t;
 for(int it=1;it<=t;it++) {
    //cout << "Case #" << it+1 << ": ";
     solve();
 }
 return 0;
}