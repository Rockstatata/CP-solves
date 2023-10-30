#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,i=0,j=0;
    cin>>n>>m;
    int num1[n],num2[m],num3[n+m];
    for(int i = 0;i<n;i++){
        cin>>num1[i];
    }
    for(int i = 0;i<m;i++){
        cin>>num2[i];
    }
    while(i<n || j<m){
        if(j==m || i<n && num1[i]<num2[j]){
            num3[i+j]=num1[i];
            i++;
        }
        else{
            num3[i+j]=num2[j];
            j++;
        }
    }
    for(int i = 0;i<n+m;i++){
        cout<<num3[i]<<" ";
    }
}