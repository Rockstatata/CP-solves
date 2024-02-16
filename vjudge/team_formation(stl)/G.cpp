#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<long long>v(n,0),ct(n,0);
    set<long long>s;
    for(int i = 0;i<n;i++){
        cin>>v[i];
    }
    for(int i =n-1;i>=0;i--){
        s.insert(v[i]);
        ct[i]=s.size();
    }
    for(int i = 0;i<m;i++){
        long long q;
        cin>>q;
        cout<<ct[q-1]<<endl;
    }
}