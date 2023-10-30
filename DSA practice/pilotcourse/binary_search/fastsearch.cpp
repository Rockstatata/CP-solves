#include<bits/stdc++.h>
 
using namespace std;

int bsr(vector<int> &v,int l,int r,int x){
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

int bsl(vector<int> &v,int l,int r,int x){
    int m;
    while(l+1<r){
        m = (l+r)/2;
        if(v[m]<=x){
            l=m;
        }
        else if(v[m]>x){
            r=m;
        }
    }
    return l;
}

void fastsearch(vector<int> &v,int l ,int r){
    int left = bsl(v,0,v.size()-1,r);
    int right = bsr(v, 0, v.size()-1,l);
    int result;
    if(left == 0 || right == v.size()+1){
        result = 0;
    }
    else{
        result = left-right+1;
    }
    cout<<result<<" ";
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k,num,l,r;
    cin>>n;
    vector<int>v;
    v.push_back(-2e9);
    for(int i = 0;i<n;i++){
        cin>>num;
        v.push_back(num);
    }  
    v.push_back(2e9);
    sort(v.begin(),v.end());
    cin>>k;
    for(int i = 0;i<k;i++){
        cin>>l>>r;
        fastsearch(v,l,r);
    }
}