#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n;
        int pref[3] {};
        for(int i = 0;i<n;i++){
            cin>>x;
            pref[x]++;
        }
        if(pref[1]==0){
            x=pref[2];
            if(x%2==0){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        else if(pref[2]==0){
            if(pref[1]%2==0){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        else{
            int sum = pref[2] * 2 + pref[1] * 1;
            if(sum%2){
                cout<<"NO"<<endl;
            }
            else{
                cout<<"YES"<<endl;
            }
        }
    }
}