#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int a,b,n,big1,big2,cnt=0;
        cin>>a>>b>>n;
        if(a>=b){
            big1=a;
            big2=a+b;
            cnt++;
        }
        else{
            big1=b;
            big2=a+b;
            cnt++;
        }
        while(big1<=n && big2<=n){
            if(cnt%2){
                big1+=big2;
            }
            else{
                big2+=big1;
            }
            cnt++;
        }
        cout<<cnt<<endl;
    }
}