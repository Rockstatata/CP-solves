#include<bits/stdc++.h>

/* Given N strings, print unique strings
in lexiographical order with their frequency
N<=10^5
|S|<=100*/
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    map<string,int>m;
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        string s;
        cin>>s;
        m[s]++;
    }
    for(auto pr:m){
        cout<<pr.first<<" "<<pr.second<<endl;
    }
}