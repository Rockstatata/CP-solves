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

void dfs(int row,int col,vector<vector<char>>& vp,vector<vector<int>>& vis, string& mini,multiset<string>& ans){
    int n = vp.size();
    int m = vp[0].size();
    int delrow[] = {0,1};
    int delcol[] = {1,0};
    for(int i = 0;i<2;i++) {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i]; 
       
        if(nrow >=0 && nrow <n && ncol >= 0 && ncol < m 
        && !vis[nrow][ncol]) {
            mini+=vp[nrow][ncol];
            if(nrow==n-1 && ncol==m-1){
                ans.insert(mini);
                mini.pop_back();
                return;
            }
            dfs(nrow, ncol, vp, vis,mini,ans); 
            mini.pop_back();
        }
    }
}

void dfsbase(vector<vector<char>>vp){
    multiset<string>ans;
    string mini;
    mini+=vp[0][0];
    int n = vp[0].size();
    vector<vector<int>> vis(2, vector<int>(n,0));
    dfs(0,0,vp,vis,mini,ans);
    cout<<*ans.begin()<<endl;
    cout<<ans.count(*ans.begin())<<endl;
}

 

void solve(){
    int n;
    cin>>n;
    vector<vector<char>> vp;
    char c;
    for(int i =0;i<2;i++){
        vector<char>mini;
        for(int j = 0;j<n;j++){
            cin>>c;
            mini.pb(c);
        }
        vp.pb(mini);
    }
    dfsbase(vp);
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