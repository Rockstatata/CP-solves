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
    int len;
    cin>>len;
    int cost[26][26];
    vector<pair<int,int>>minrow;
    for(int i = 0;i<26;i++){
        for(int j = 0;j<26;j++){
            cin>>cost[i][j];
        }
        int min = *min_element(cost[i],cost[i]+26);
        int minind;
        for(int j = 0;j<26;j++){
            if(min==cost[i][j]){
                minind = j;
                break;
            }
        }
        minrow.push_back({minind,min});
    }
    sort(minrow.begin(),minrow.end());
    cout<<"MINIMUM"<<endl;
    for(int i= 0 ;i<26;i++){
        cout<<minrow[i].first<<" ";
    }
    cout<<endl;
    for(int i= 0 ;i<26;i++){
        cout<<minrow[i].second<<" ";
    }
    cout<<endl;

    int min = minrow[0].second;
    


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