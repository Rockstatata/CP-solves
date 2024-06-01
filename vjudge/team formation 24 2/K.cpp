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
    set<string>s1 {"Alice","Ariel","Aurora","Phil","Peter","Olaf","Phoebus","Ralph","Robin"};
    set<string>s2 {"Bambi","Belle","Bolt","Mulan","Mowgli","Mickey","Silver","Simba","Stitch"};
    set<string>s3 {"Dumbo","Genie","Jiminy","Kuzko","Kida","Kenai","Tarzan","Tiana","Winnie"};
    int n,cur=1,sum=0;
    cin>>n;
    string s;
    for(int i = 0;i<n;i++){
        cin>>s;
        if(s1.find(s)!=s1.end()){
            if(cur!=1){
                sum+=abs(cur-1);
                cur = 1;
            }
        }
        else if(s2.find(s)!=s2.end()){
            if(cur!=2){
                sum+=abs(cur-2);
                cur = 2;
            }
        }
        else{
            if(cur!=3){
                sum+=abs(cur-3);
                cur = 3;
            }
        }
    }
    cout<<sum<<endl;
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