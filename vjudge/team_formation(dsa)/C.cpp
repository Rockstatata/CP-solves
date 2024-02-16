#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int num[n], sum=0, ans=0;
    int hash[181] = {};
    for(int i = 0;i<n;i++){
        cin>>num[i];
        hash[num[i]]++;
        sum+=num[i];
    }   
    int i = 0,j=n-1;
    if(sum%360==0){
        cout<<"YES"<<endl;
    }
    else{
        while(i<j){
            if(num[i]==num[j]){
                num[i]=0;
                num[j]=0;
                i++;
                j--;
            }
            else if(num[i]>num[j]){
                num[i] = num[i]-num[j];
                num[j]=0;
                j--;
            }
            else{
                num[j] = num[j]-num[i];
                num[i]=0;
                i++;
            }
        }
        for(int i=  0;i<n;i++){
            if(num[i]!=0){
                cout<<"NO"<<endl;
                return 0;
            }
        }
        cout<<"YES"<<endl;
    }
}