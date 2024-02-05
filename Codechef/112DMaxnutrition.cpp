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
    int n,total=0;
    cin>>n;
    int food[n],nutrition[n];
    for(int i = 0;i<n;i++){
        cin>>food[i];
    }
    for(int i = 0;i<n;i++){
        cin>>nutrition[i];
    }
    vector<pair<int,int>>foods;
    int cnt[n+1] {0};
    for(int i = 0;i<n;i++){
        foods.push_back({nutrition[i],food[i]});
    }
    sort(foods.rbegin(),foods.rend());
    for(int i = 0;i<n;i++){
        if(cnt[foods[i].second]==1){
            continue;
        }
        if(foods[i].first < 0){
            continue;
        }
        total+=foods[i].first;
        cnt[foods[i].second]++;
    }
    
    cout<<total<<endl;

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