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
    int n;
    cin>>n;
    long long arr[n];
    long long pref[n];
    long long count=0,i = 0,maxi = -1,ind=0;
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    pref[0] = arr[0];
    for(int i =1;i<n;i++){
        pref[i] = pref[i-1] + arr[i]; 
        //cout<<pref[i]<<endl;
    }
    i=0;
    while(i<n){
        if(arr[i]>=maxi) {
            maxi = arr[i];
            ind = i;
        }
        if(i==0){
            if(arr[i]==0){
                count++;
            }
        }
        else{
            if(ind==i){
                if(pref[i-1]==arr[i]){
                    count++;
                }
            }
            else{
                ll val = pref[i] - arr[ind];
                //cout<<val<<endl;
                if(val==arr[ind]){
                    count++;
                }
            }
        }
        i++;
    }
    cout<<count<<endl;
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