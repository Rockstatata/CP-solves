
#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,count=0,carr[30]={},res=0,flag=0;
    //string s;
    cin>>n>>m;
    string x[n];
    vector<int>v[n];
    for(int i = 0;i<n;i++){
        cin>>x[i];
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(x[i][j]=='x'){
                v[i].push_back(j);
            }
        }
    }
    for(int i = 0;i<n;i++){
        count = 0;
        for(int j = 0;j<v[i].size();j++){
            for(int k=0;k<n;k++){
                for(int l=0;l<v[k].size();l++){
                    if(v[i][j]!=v[k][l] && i!=k){
                        count++;
                    }
                }
                if(count==v[k].size()){
                    res++;
                }
            }
        }
        if(v[i].size()==0){
            res+=(n-1);
        }
    }
    cout<<res<<endl;
}