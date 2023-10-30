#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,count=0;
    cin>>N;
    int arr[N+1];
    for(int i=1;i<=N;i++){
        cin>>arr[i];
    } 
    for(int i = 1;i<=N;i++){
        if((i)==arr[arr[i]]){
            count++;
        }
    } 
    cout<<count/2<<endl;
}