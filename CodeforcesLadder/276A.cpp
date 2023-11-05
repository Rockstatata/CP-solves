#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k,a,b;
    cin>>n>>k;
    vector<pair<int,int>>rest;
    int joy[n];
    for(int i = 0;i<n;i++){
        cin>>a>>b;
        rest.push_back({a,b});
    }
    //sort(rest.rbegin(),rest.rend());
    for(int i = 0;i<n;i++){
        if(rest[i].second <= k){
            joy[i]=rest[i].first;
        }
        else{
            joy[i]=rest[i].first-(rest[i].second-k);
        }
    }
    int max = -(1e+9);
    for(int i = 0;i<n;i++){
        if(joy[i]>=max){
            max=joy[i];
        }
    }
    cout<<max<<endl;
}