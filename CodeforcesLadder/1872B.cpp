#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n;
        pair<int,int>p[n];
        int arr[n];
        for(int i = 0;i<n;i++){
            cin>>p[i].first>>p[i].second;
            arr[i]=p[i].first+floor((p[i].second - 1)/2.0);
        }
        m = *min_element(arr,arr+n);
        cout<<m<<endl;
    }
}