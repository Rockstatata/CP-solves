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
 

int win(char board[3][3],vector<pair<int,int>>empty){
    int xdir[] {1,0,-1,0,1,-1,1,-1};
    int ydir[] {0,1,0,-1,1,-1,-1,1};
    for(auto i:empty){
        int x = i.first;
        int y = i.second;
        for(int j = 0;j<9;j++){
            int newx = x+xdir[j];
            int newy = y+ydir[j];
            if((newx>=0 && newx<=2) || (newy>=0 && newy<=2)){
                
            }
        }
    }
}

void solve(){
    char board[3][3];
    vector<pair<int,int>>empty;
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            cin>>board[i][j];
            if(board[i][j] == '#'){
                empty.push_back({i,j});
            }
        }
    }

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