#include<bits/stdc++.h>
 
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        long long int n,x=0,tot=0;
        cin>>n;
        for(long long int i = 29;i>=0;i--){
            if(n%(int((pow(2,i))-1))==0){
                x=n/(int((pow(2,i))-1));
                break;
            }
        }
        cout<<x<<endl;
    }
}