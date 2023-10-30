#include<bits/stdc++.h>
 
using namespace std;

int fact(int n){
    if(n==0){
        return 1;
    }
    return n*(fact(n-1));
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k=3;
    cin>>n;
    int num[n];
    for(int i = 0;i<n;i++){
        cin>>num[i];
    }
    int size = fact(n)/((fact(k))*fact(n-k));
    int res[size] {};
    res[0]=accumulate(num,num+3,0);
    for(int i = 1,j=3;i<size;i++,j++){
        res[i]=res[i-1]+num[j]-num[i-1];
    }
    for(int i = 0;i<size;i++){
        cout<<res[i]<<" ";
    }
}