#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,b,c,x,cnt=0;
    cin>>x>>a>>b>>c;
    for(int i=0;i*a<=x;i++){
        for(int j=0;j*b+i*a<=x;j++){
            int k = (x-(i*a+j*b))/c;
            if(i*a+j*b+k*c==x){
                cnt=max(cnt,i+j+k);
            }
        }
    }
    cout<<cnt<<endl;
}