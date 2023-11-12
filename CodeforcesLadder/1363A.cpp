#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int i,n,x,oddc=0,evenc=0,a;
        cin>>n>>x;
        for(int i = 0;i<n;i++){
            cin>>a;
            if(a%2) oddc++;
            else evenc++;
        }
        for(i = 1;i<=x;i+=2){
            if(i<=oddc){
                if(i+evenc>=x){
                    cout<<"Yes"<<endl;
                    break;
                }
            }
            else{
                cout<<"No"<<endl;
                break;
            }
        }
        if(i>x){
            cout<<"No"<<endl;
        }
            
    }
}