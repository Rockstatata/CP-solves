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
 

int lower_bound(int arr[],int size, int value){
        int l = 0, r=size-1;
        int mid = (l+r)/2;
        while(l<=r){
            mid = (l+r)/2;
            int thing = arr[mid];
            if(value<=thing){
                r=mid-1;
            }
            else if(value>thing){
                l=mid+1;
            }  
        }
        return r;
    }

void solve(){
    int n,x,anss=0;
    cin>>n>>x;
    int taps[n];
    for(int i = 0;i<n;i++){
        cin>>taps[i];
        if(taps[i]==x) anss = 1;
    }
    if(anss){
        cout<<anss<<endl;
        return;
    }
    sort(taps,taps+n);
    if(x<taps[0]){
        cout<<-1<<endl;
        return;
    }
    else if(x>taps[n-1]){
        cout<<-1<<endl;
        return;
    }
    int low = lower_bound(taps,n,x);
    int tapa = taps[low],tapb = taps[low+1];
    float y = float((((tapb-x)*1.0)/(1.0*(tapb-tapa))));
    if(y<=1){
        cout<<2<<endl;
    }
    else{
        cout<<-1<<endl;
    }

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