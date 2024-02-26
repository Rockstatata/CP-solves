#include <bits/stdc++.h>

using namespace std;
#define fast {ios_base::sync_with_stdio(false); cin.tie(0);}
typedef long long ll;
#define int long long
#define float long double

void solve()
{
    int n,m;
    cin >> n >> m;
    deque<int> d;
    int x=1;
    int a[n];
    for(int k,i=0;i<n;i++){ 
        cin >> k;
        d.push_back(k);
    }
    string s;
    cin >> s;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int xx;
        if(s[i]=='L') {
            v.push_back(d.front());
            d.pop_front();
        }
        else{ 
            v.push_back(d.back());
            d.pop_back();
        }
    }
    stack<int> st;
    for(int i=v.size()-1;i>=0;i--)
    {
        x=(x*v[i])%m;
        st.push(x);
    }
    while(!st.empty()){
        cout << st.top() << ' ';
        st.pop();
    }  
    cout << endl;
}

signed main()
{
    fast
    int t=1;
    cin >> t;
    for(int cs=1;cs<=t;cs++)
    {
        solve();
    }
    return 0;
}