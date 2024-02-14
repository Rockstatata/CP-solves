#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
    int t, n, x;
    ll c;
    cin >> t;
    while(t--){
        map<int, ll> m;
        cin >> n;
        c = 0;
        for(int i = 1; i<=n; i++){
            cin >> x;
            m[x-i]++;
        }
        for(auto &i: m){
            if(i.second > 1) c += i.second * (i.second-1) / 2;
        }
        cout << c << endl;
    }
}