#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,x,y,w,z,count=0;
    cin>>n;
    vector<pair<int,int>>v;
    pair<int,int>p;
    for(int i = 0;i<n;i++){
        cin>>x>>y;
        p.first=x;
        p.second=y;
        v.push_back(p);
    }
    sort(v.begin(),v.end());
    for(int i = 1;i<n;i++){
        if(v[i].second<v[i-1].second){
            cout<<"Happy Alex"<<endl;
            return 0;
        }
    }
    cout<<"Poor Alex"<<endl;
}