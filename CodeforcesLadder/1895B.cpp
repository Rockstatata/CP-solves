#include <bits/stdc++.h>
using namespace std; 
typedef long long int ll;
const int N = 1e5 + 2;
void solve() {
    int n;
    cin >> n;
    vector<int> v(2*n);
    for(auto &x : v) cin >> x;

    sort(v.begin(), v.end());
    vector<pair<int, int>> ans;
    int l = 0, r = 2 * n - 1;;
    while(l < r) {
        ans.push_back({v[l++], v[r--]});
    }

    int sum = 0;
    for(int i = 1; i < n; i++) {
        sum += (abs(ans[i].first - ans[i - 1].first));
        sum += (abs(ans[i].second - ans[i - 1].second));
    }

    cout << sum << "\n";
    for(auto [x, y] : ans) {
        cout << x << " " << y << "\n";
    }
}   
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, cs = 1;
    cin >> t; 
    while(t--) {
        //cout << "Case " << cs++ << ": ";
        solve();
    }
    return 0;
}