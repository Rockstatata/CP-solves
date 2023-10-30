#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        string x;
        cin>>x;
        if(x[0]>x[2] && x[1]!='b'){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }   
}