#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(ll x, ll y, ll z, ll k) {
    ll ans = 0;
    for (ll i = 1; i <= x; i++) {
        for (ll j = 1; j <= y; j++) {
            for (ll l = 1; l <= z; l++) {
                if (i * j * l == k) {
                    ans += (x - i + 1) * (y - j + 1) * (z - l + 1);
                }
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        ll x, y, z, k;
        cin >> x >> y >> z >> k;
        cout << solve(x, y, z, k) << "\n";
    }
    return 0;
}