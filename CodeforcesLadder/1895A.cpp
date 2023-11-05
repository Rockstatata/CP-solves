#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int x,y,k,time=0;
        cin>>x>>y>>k;
        if(x<=y){
            time+=x;
            while(k--){
                time++;
                if(time==y){
                    break;
                }
            }
            if(time<y){
                time+=(2*(y-time));
            }
        }
        else{
            time=x;
        }
        cout<<time<<endl;
    }
}