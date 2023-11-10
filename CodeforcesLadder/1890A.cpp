#include<bits/stdc++.h>
 
using namespace std;

void solve(){
   int n;
    cin >> n;
    map<int, int> st;
    for(int i =1 ; i <= n; i++) {
        int x; cin >> x;
        st[x]++;
    }
 
    if(st.size() == 1) {
        cout << "Yes\n";
    }
    else if(st.size() == 2) {
        int val = st.begin()->second;
        if(n % 2 == 0) {
            if(val == n / 2) {
                cout << "Yes\n";
            }
            else {
                cout << "No\n";
            }
        }
        else {
            if(val == n / 2 || val == n / 2 + 1) {
                cout << "Yes\n";
            }
            else {
                cout << "No\n";
            }
        }
    }
    else cout << "No\n";
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}