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
        int diff = abs(a-b);
        float times = diff / (c*2.0);
        int result = ceil(times);
        cout<<result<<endl;
    }   
}