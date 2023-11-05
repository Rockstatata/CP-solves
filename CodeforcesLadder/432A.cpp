#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k,count=0,team;
    cin>>n>>k;
    int part[n];
    for(int i = 0;i<n;i++){
        cin>>part[i];
    }
    for(int i = 0;i<n;i++){
        if(part[i]+k<=5){
            count++;
        }
    }
    team = count/3;
    cout<<team<<endl;
}