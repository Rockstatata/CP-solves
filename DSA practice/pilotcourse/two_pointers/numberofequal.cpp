#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long int n,m,i=0,j=0,count1=0,count2=0,ans=0;
    cin>>n>>m;
    long long int num1[n],num2[m],num3[m];
    for(int i = 0;i<n;i++){
        cin>>num1[i];
    }
    for(int i = 0;i<m;i++){
        cin>>num2[i];
    }
    while(i<n && j<m){
        if(num1[i]==num2[j]){
            count1=1;
            while((i+1)<n && num1[i+1]==num1[i]){
                count1++;
                i++;
            }
            i++;
            count2=1;
            while((j+1)<m && num2[j+1]==num2[j]){
                count2++;
                j++;
            }
            j++;
            ans += count1*count2;
        }
        else if(num1[i]<num2[j]){
            i++;
        }
        else{
            j++;
        }
    }
    cout<<ans<<endl;
}