#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
    if(b == 0) return a;
    return gcd(b, a % b);
}

void solve()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll ab = gcd(a, b);
    ll cd = gcd(c, d);
    a = a / ab;
    b = b / ab;
    c = c / cd;
    d = d / cd;
    if (a * d == b * c) cout << 0 << endl;
    else if (a == 0 || c == 0) cout << 1 << endl;
    else if ((a * d) % (b * c) == 0 || (b * c) % (a * d) == 0) {
        cout << 1 << endl;
    }
    else {
        cout << 2 << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t = 1, case_number = 1;
    cin >> t;
    while(t--)
    {
        //cout << "Case " << case_number++ << ":\n";
        solve();
    }
    return 0;
}