#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,b;
    cin>>a>>b;
    int arr[a];
    for(int i = 0;i<a-1;i++){
        cin>>arr[i];
    }
    for(int i = 0;i<a-1;){
        i+=arr[i];
        if(i==(b-1)){cout<<"YES"<<endl;return 0;}
    }
    cout<<"NO"<<endl;
}