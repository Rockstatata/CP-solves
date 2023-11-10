#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		vector<int> cnt(26, 0);
		for (int i = 0; i < n; i++)  {
			cnt[s[i] - 'a']++;
		}
		int odd = 0;
		for (int i = 0; i < 26; i++) {
			odd += (cnt[i] % 2);
		}
		cout << (k >= odd - 1 ? "YES" : "NO")<< "\n";
    }
}