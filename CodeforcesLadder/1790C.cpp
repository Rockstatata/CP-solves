#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
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
 
int n;

void solve(){
    // int n,x;
    // cin>>n;
    // int m = n-1;
    // vector<int>v[n]={},ans[m]={},sol;
    // for(int i = 0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //        cin>>x;
    //        v[i].push_back(x); 
    //     }
    // }
    // for(int i = 0;i<m;i++){
    //     for(int j = 0;j<n;j++){
    //         x=v[j][i];
    //         ans[i].push_back(x);
    //     }
    // }
    // sol.push_back(ans[0][0]);
    // for(int i = 0;i<m;i++){
    //     for(int j = 0;j<n-1;j++){
    //         for(int k=j+1;k<n;k++){
    //             int len = sol.size();
    //             if(ans[i][j]==ans[i][k]){
    //                 for(int l = 0;l<len;l++){
    //                     if(sol[l]!=ans[i][j]){
    //                         sol.push_back(ans[i][j]);
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }
    // for(int i = 0;i<sol.size();i++){
    //     cout<<sol.at(i)<<endl;
    // }
    cin >> n;
    vector<vector<int>>perm(n, vector<int>(n - 1));
    vector<int>p(n, 0);
    vector<int>cnt(n + 1, 0);
    for(int i = 0; i < n; i++){
        p[i] = i + 1;
        for(int j = 0; j < n - 1; j++){
            cin >> perm[i][j];
            if(j == 0) cnt[perm[i][j]]++;
        }
    }
    for(int i = 1; i <= n; i++){
        if(cnt[i] == n - 1){
            p[0] = i;
            break;
        }
    }
    for(int i = 0; i < n; i++){
        if(perm[i][0] != p[0]){
            for(int j = 0; j < n - 1; j++){
                p[j + 1] = perm[i][j];
            }
        }
    }
    for(int i = 0; i < n; i++) cout << p[i] << ' ';
    cout << endl;
}
int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   fast_cin();
   ll t;
   cin >> t;
   while(t--){
       solve();
   }
   return 0;
}