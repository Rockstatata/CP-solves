#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,cnt1=0,cnt2=0;
    cin>>n;
    map<string,int>m;
    string x;
    for(int i=0;i<n;i++){
        cin>>x;
        m[x]++;
    }
    if(m.begin()->second > m.rbegin()->second){
        cout<<m.begin()->first<<endl;
    }
    else{
        cout<<m.rbegin()->first<<endl;
    }
}