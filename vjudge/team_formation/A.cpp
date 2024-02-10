#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long int n,moves=0;
    cin>>n;
    long long int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<n;i++){
        if(arr[i]<arr[i-1]){
            moves += abs(arr[i] - arr[i-1]);
            arr[i]+= abs(arr[i] - arr[i-1]);
        }
    }
    cout<<moves<<endl;
}