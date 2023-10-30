#include<bits/stdc++.h>
 
using namespace std;

int binarysearch(vector<int> &v,int l,int r,int x){
    int m;
    while(l+1<r){
        m = (l+r)/2;
        if(v[m]<x){
            l=m;
        }
        else if(v[m]>=x){
            r=m;
        }
    }
    return r;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k,num;
    cin>>n>>k;
    vector<int>m;
    m.push_back(-2e9);
    for(int i = 0;i<n;i++){
        cin>>num;
        m.push_back(num);
    }
    m.push_back(2e9);
    for(int i=0;i<k;i++){
        cin>>num;
        int result = binarysearch(m,0,n+1,num);
        cout<<result<<endl;
    }
}