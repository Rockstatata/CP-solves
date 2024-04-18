#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        long long y,x,ans,ans2;
        cin>>x>>y;
        if(y>=x){
            ans = y*y;
            ans2 = (y-1)*(y-1);
            if(y%2){
                ans = ans-(x-1);
            }  
            else{
                ans = ans2+x;
            }
        }
        else{
            ans = x*x;
            ans2 = (x-1)*(x-1);
            if(x%2){
                ans = ans2+y;
            }  
            else{
                ans = ans-(y-1);
            }
        }
        cout<<ans<<endl;
    }
}