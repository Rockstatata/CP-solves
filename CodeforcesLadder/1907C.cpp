#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        string s;
        int n;
        int arr[26] = {};
        cin>>n;
        cin>>s;
        for(int i = 0;i<n;i++){
            arr[s[i]-'a']++;
        }
        int maxi = *max_element(arr,arr+26);
        int ans = max(n%2,2*maxi-n);
        cout<<ans<<endl;
    }
}