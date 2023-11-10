#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,m,change=0,can=1,j;
        cin>>n;
        int arr[n+1];
        for(int i = 1;i<n+1;i++){
            cin>>arr[i];
        }
        m=log2(n);
        for(int i = 0;i<=m;i++){
            change = 0;
            for(j=1;j<=int(pow(2,i));j++){
                if(n!=int(pow(2,i))) if(arr[int(pow(2,i))]>arr[int(pow(2,i))+1])change=1;
                arr[j]-=change;
                if(j==int(pow(2,i))){
                    if(j+1>n){
                        continue;
                    }
                    if(arr[j]>arr[j+1])j=0;
                }
            }
        } 
        for(int i =1;i<n;i++){
            if(arr[i]>arr[i+1]){
                cout<<"NO"<<endl;
                can=0;
                break;
            }
        }
        if(can)cout<<"YES"<<endl;
    }
}