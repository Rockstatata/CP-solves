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
    long long n;
    cin>>n;
    long long arr[n];
    vector<long long>neg;
    int pos = 0;
    long long i = 0,c=0;
    forn(i,n){
        cin>>arr[i];
        if(arr[i]<0){
            pos = i;
            neg.push_back(arr[i]);
        }
    }
    c = arr[0];
    if(pos==0) c = abs(c);
    int j = 2;
    for(int i = 1;i<n;i++){
        if(i>=pos){
            c=abs(c+arr[i]);
        }
        else if(c+arr[i]<0){
            if(i+1<n){
                if(arr[i+1]>0){
                    if(j<neg.size() && abs(neg[j])>=abs(c+arr[i])){
                        c=(c+arr[i]);
                        j++;
                    }
                    else{
                        c=abs(c+arr[i]);
                    }

                }
                else{
                    c=(c+arr[i]);
                }
            }
        }
        else{
            c = (c+arr[i]);
        }
        //cout<<c<<endl;
    }
    cout<<c<<endl;
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