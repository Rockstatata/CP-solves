#include<bits/stdc++.h>
 
using namespace std;

void solve(){
    int a,b,x,y,w,z;
    int dx=1,dy=1,cnt=0;
    cin>>a>>b>>x>>y>>w>>z;
    while(x!=w && y!=z){
        if(x==a){
            dx=-1;
        }
        if(y==b){
            dy=-1;
        }
        if(x==1){
            dx=1;
        }
        if(y==1){
            dy=1;
        }
        x+=dx;
        y+=dy;
        cnt++;
    }
    cout<<cnt<<endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}