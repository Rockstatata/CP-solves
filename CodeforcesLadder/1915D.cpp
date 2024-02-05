#include <bits/stdc++.h> 
#include <chrono>
#include <random>
#include <iostream>
#include <cmath>
#include <fstream>
#include <string.h>
 
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
    string word;
    char track[n];
    vector<string>v;
    string x;
    cin>>word;
    for(int i = 0;i<n;i++){
        if(word[i]=='a' || word[i] == 'e'){
            track[i]='V';
        }
        else{
            track[i]='C';
        }
    }
    if(n==1){
        cout<<word[0]<<endl;
    }
    else{
        int l = 0,r=0;
        while(l<(n-1)){
            if(track[l]=='C'){
                r++;
                if(track[r]=='V'){
                    r++;
                    if(track[r]=='C'){
                        if((r+1)<n && track[r+1]!='C')r--;
                        x = word.substr(l,r-l+1);
                        v.push_back(x);
                        r++;
                    }
                    else{
                        r--;
                        x= word.substr(l,r-l+1);
                        v.push_back(x);
                        r++;
                    }
                }
            }
            l=r;
        }
    }
    int len = v.size();
    for(int i = 0;i<len-1;i++){
        cout<<v[i]<<".";
    }
    cout<<v[len-1]<<endl;
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