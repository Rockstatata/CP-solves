#include <bits/stdc++.h>
#include <chrono>
#include <random>
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)                      
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

int bfs(int n, int m, int x1, int y1, int x2, int y2, vector<vector<char>> graph)
{
    int movex[] = {1, -1, 0,0};
    int movey[] = {0, 0, 1, -1};
    queue<pair<int, int>> q1, q2;
    q1.push({x1, y1});
    q2.push({x2, y2});
    int k1 = 1,count=0;
    while (!q1.empty() || !q2.empty())
    {
        int jx = q1.front().first;
        int jy = q1.front().second;
        if((jx==n-1 || jy==m-1 || jx==0 || jy==0)){
                return count;
        }
        q1.pop();
        for (int i = 0; i < 4; i++)
        {
            int x3 = jx + movex[i];
            int y3 = jy + movey[i];
            if ((x3 >= n || x3 < 0) || (y3 >= m || y3 < 0) || graph[x3][y3] != '.')
            {
                continue;
            }
            graph[jx][jy] = '.';
            graph[x3][y3] = 'J';
            q1.push({x3, y3});
            if((x3==n-1 || y3==m-1 || x3==0 || y3==0)){
                continue;
        }
        count++;
        }
        int k2=0;
        for (int j = 0; j < k1; j++)
        {
            int fx = q2.front().first;
            int fy = q2.front().second;
            q2.pop();
            k1--;
            for (int i = 0; i < 4; i++)
            {
                int x3 = fx + movex[i];
                int y3 = fy + movey[i];
                if ((x3 >= n || x3 < 0) || (y3 >= m || y3 < 0))
                {
                    continue;
                }
                if (graph[x3][y3] == 'J')
                {
                    return -1;
                }
                if(graph[x3][y3]=='#'){
                    continue;
                }
                q1.push({x3, y3});
                graph[x3][y3] = 'F';
                k2++;
            }
            if(j==k1){
                k1=k2;
                break;
            }
        }
    }
    return -1;
}

void solve()
{
    int n, m, x1, y1, x2, y2;
    cin >> n >> m;
    vector<vector<char>> graph;
    vector<char> line;
    char x;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> x;
            line.push_back(x);
            if (x == 'J')
            {
                x1 = i;
                y1 = j;
            }
            else if (x == 'F')
            {
                x2 = i;
                y2 = j;
            }
        }
        graph.push_back(line);
        line.clear();
    }
    int ans = bfs(n, m, x1, y1, x2, y2, graph);
    if(ans==-1){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    cout<<ans<<endl;
}
int main()
{
    fast_cin();
    ll t = 1;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        cout << "Case " << it<< ": ";
        solve();
    }
    return 0;
}