#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int num[n];
    long long int i = 0,count = 0;
    for(int i = 0;i<n;i++){
        cin>>num[i];
    }
    while(i<n-1){
        if(num[i]>num[i+1]){
            count+=(num[i]-num[i+1]);
            num[i+1]+=(num[i]-num[i+1]);
        }
        i++;
    }
    cout<<count<<endl;
}