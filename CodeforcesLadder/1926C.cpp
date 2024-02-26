#include<bits/stdc++.h>
 
using namespace std;

typedef long long ll;

int arr[500001] {0};

void precompute(){
    ll mini = 0;
    for(int i = 1;i<=500000;i++){
        ll j=i;
        for (mini; j > 0; mini += j % 10, j /= 10);    
        arr[i] = mini;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    precompute();
    while(t--){
        ll n;
        cin>>n;
        cout<<arr[n]<<endl;
    }
}