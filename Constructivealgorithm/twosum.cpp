#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }   
    for(int i = 0;i<n-1;i++){
        for(int j = i+1;j<n;j++){
            if((arr[i]+arr[j])%n==0){
                cout<<i<<" "<<j<<endl;
            }
        }
    }
}