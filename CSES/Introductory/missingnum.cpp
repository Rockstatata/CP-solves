#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,a;
    cin>>n;
    int pref[200001] = {};
    for(int i =0;i<n;i++){
        cin>>a;
        pref[a]++;
    }
    for(int i = 1;i<=n;i++){
        if(pref[i]==0){
            cout<<i<<endl;
            break;
        }
    }
}