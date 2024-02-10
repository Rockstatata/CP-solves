#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    int i = 1;
    while(i<=t){
        long long w,count=0;
        long long m,n;
        cin>>w;
        long long ans = w;
        if(w%2){
            cout<<"Case "<<i<<": Impossible"<<endl;
        }
        else{
            while(w>0){
                if(w%2) break;
                w/=2;
                count++;
            }
            //if(w==0)count--;
            m = pow(2,count);
            n = ans/m;
            cout<<"Case "<<i<<": "<<n<<" "<<m<<endl;
        }
        i++;
    }   
}