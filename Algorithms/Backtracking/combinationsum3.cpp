#include<bits/stdc++.h>
using namespace std;
int par[4];
char sm[4] = {'-', '/', '+', '*'};
// 0 1 2 3
// - / + *
int x;
bool check(int pos, int pre, vector<int> &v) {
    //cout << pos << " " << " " << pre << " " << x << "\n";
    if(pos == 4) return (pre == x);
    bool ans = 0;
    if(pre >= x) {
        ans |= check(pos + 1, pre - v[pos], v);
        if(ans) {
            par[pos] = 0;
            return 1;
        }
        if(v[pos] > 0) ans |= check(pos + 1, pre / v[pos], v);
        if(ans) {
            par[pos] = 1;
            return 1;
        }
    }
    else {
        ans |= check(pos + 1, pre + v[pos], v);
        if(ans) {
            par[pos] = 2;
            return 1;
        }
        ans |= check(pos + 1, pre * v[pos], v);
        if(ans) {
            par[pos] = 3;
            return 1;
        }
    }
    return 0;
}
int main()
{
    vector<int> v(4);
    for(int i = 0; i < 4; i++) {
        cin >> v[i];
    }
    cin >> x;
    sort(v.begin(), v.end());
    do {
        memset(par, 0, sizeof par);
        if(check(0, 0, v)) {
            cout << v[0];
            for(int i = 1; i < 4; i++) {
                cout << sm[par[i]] << v[i];
            }
            cout << " = " << x << "\n";
            break;
        }
    }while(next_permutation(v.begin(), v.end()));
    return 0;
}

/*
4 1 8 7
25
1 2 3 4
24
*/
