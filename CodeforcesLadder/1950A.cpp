#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        if(a<b && b<c) cout<<"STAIR"<<endl;
        else if(b>a && b>c) cout<<"PEAK"<<endl;
        else cout<<"NONE"<<endl;
    }
}