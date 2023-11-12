#include<bits/stdc++.h>
 
using namespace std;

void solve(){
    int num[3];
    for(int i = 0;i<3;i++){
        cin>>num[i];
    }
    sort(num,num+3);
    if(num[0] == num[1]){
        if(num[2]%2==0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    else if(num[1]==num[2]){
        if(num[0]%2==0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    else{
        if(num[2]==num[0]+num[1]){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
} 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}