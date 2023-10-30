#include<bits/stdc++.h>
 
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int l,r,a,b,i=0,j=0,k=0;
        cin>>l>>r;
        for(i = l;i<=r;i++){
            for(j =2; j<=sqrt(i);j++){
                if(i%j==0){
                    cout<<j<<" "<<(i-j)<<endl;
                    i = -1;
                    break;
                }
            }
            if(i==-1){
                break;
            }
        }
        if(i==r+1){
            cout<<"-1"<<endl;
        }
    }
}