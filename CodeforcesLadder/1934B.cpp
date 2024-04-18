#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lmax LLONG_MAX

ll small( ll n)
{
    ll ans=0;
    if (n >= 15)
    {
        ll x = n / 15;
        n = n - x * 15;
        ans += x;
    }

    if (n >= 10)
    {
        ll x = n / 10;
        n = n - x * 10;
        ans += x;
    }

    if (n >= 6)
    {
        ll x = n / 6;
        n = n - x * 6;
        ans += x;
    }

    if (n >= 3)
    {
        ll x = n / 3;
        n = n - x * 3;
        ans += x;
    }

    if (n >= 1)
    {
        ll x = n / 1;
        n = n - x * 1;
        ans += x;
    }
    return ans;
}


void solve()
{
    ll n;
    cin >> n;
    ll ans = lmax;
    vector<ll> cv = {1, 3, 6, 10, 15};
    for(auto x:cv)
    {
        if(n-x>=0)
        {
         ans=min(ans,1+small(n-x));
        }
    }

    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}