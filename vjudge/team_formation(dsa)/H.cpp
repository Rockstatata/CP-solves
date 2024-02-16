#include<bits/stdc++.h>
 
using namespace std;

int mapp[200002] = {0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int arr[n+1];
    cin>>arr[1];
    for(int i = 2;i<=n;i++){
        cin>>arr[i];
        mapp[arr[i]]++;
    }   
}