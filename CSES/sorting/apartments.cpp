#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k,count=0;
    cin>>n>>m>>k;
    int narr[n];
    int marr[m];
    for(int i = 0;i<n;i++){
        cin>>narr[i];
    }
    for(int i = 0;i<m;i++){
        cin>>marr[i];
    }
    sort(narr,narr+n);
    sort(marr,marr+m);
    int i = 0,j = 0;
    while (i < n && j < m) {
		if (abs(narr[i] - marr[j]) <= k) {
			++i;
			++j;
			++count;
		} else {
			if (narr[i] - marr[j] > k) {
				++j;
			}
			else {
				++i;
			}
		} 
    }
    cout<<count<<endl;
}