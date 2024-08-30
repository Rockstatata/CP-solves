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
    int n,ans=0;
    cin>>n;
    int A[2*n];
    int B[2*n];
    for(int i=  0;i<n;i++){
        cin>>A[i];
    }
    for(int i=  0;i<n;i++){
        cin>>B[i];
    }
    for(int i = n;i<2*n;i++){
        A[i] = A[i-n];
    }
    for(int i = n;i<2*n;i++){
        B[i] = B[i-n];
    }
    int curr = 0, start = 0;
    for(int i = 0;i<2*n;i++){
        if(i==start+n){
            cout<<start<<endl;
            ans = 1;
            break;
        }
        curr += A[i] - B[i];
        if(curr<0){
            start = i+1;
            curr= 0;
        }
    }
    if(!ans)cout<<-1<<endl;
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