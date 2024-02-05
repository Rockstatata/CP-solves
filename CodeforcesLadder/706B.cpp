#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,r;
    cin>>n;
    vector<long long>x;
    for(int i = 0;i<n;i++){
        cin>>r;
        x.push_back(r);
    }
    int q;
    cin>>q;
    vector<long long>m;
    for(int i = 0;i<q;i++){
        cin>>r;
        m.push_back(r);
    }
    sort(x.begin(),x.end());
    for(int i = 0;i<q;i++){
        long long y = m[i];
        long long l=0,r=n-1,mid=(l+r)/2,flag=-1;
        while(l<=r){
            if(x[mid]<=y){
                flag=mid;
                l=mid+1;
                mid=(l+r)/2;
            }
            else{
                r=mid-1;
                mid=(l+r)/2;
            }
        }
        if(flag<0){
            cout<<0<<endl;
        }
        else{
            cout<<flag+1<<endl;
        }
        
    }
}