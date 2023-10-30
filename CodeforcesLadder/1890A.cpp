#include<bits/stdc++.h>
 
using namespace std;

int pref[100001] {};

void solve(){
    int n;
    cin>>n;
    int num[n];
    for(int i = 0;i<n;i++){
        cin>>num[i];
        pref[num[i]]++;
    }
    if(n==2){
        cout<<"YES"<<endl;
    }
    else{
        int count = 0;
        for(int i = 0;i<100000;i++){
            count++;
        }
        
    }
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