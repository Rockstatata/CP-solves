#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,s=0,l,r=0;
        cin>>n;
        int arr[n];
        vector<pair<int,int>>vp;
        for(int i = 0;i<n;i++){
            cin>>arr[i];
        }
        for(l = 0;l<n-1;l++){
            r++;
            for(int j = l+1;j<r;j++){
                s^=arr[l] ^ arr[j];
            }
            if(s==0){
                vp.push_back(make_pair(l+1,r+1));
            }
        }
        cout<<vp.size()<<endl;
        for(int i = 0;i<vp.size();i++){
            cout<<vp[i].first<<" "<<vp[i].second<<endl;
        }
    }
}