#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,q,a,b;
    int sum[1000000000]={};
    int place[100000]{};
    cin>>n>>q;
    int num[n];

    for(int i = 0;i<n;i++){
        cin>>num[i];
        sum[num[i]]++;
        place[i]=num[i];
    }
    for(int j=0;j<q;j++){
        cin>>a>>b;
        if(sum[a]<b){
            cout<<"-1"<<endl;
        }
        else{
            
        }
    }
}