#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        long long sum = 0,avg = 0,temp=0,flag=0,flag2=0;
        for(int i=  0;i<n;i++){
            cin>>arr[i];
            sum+=arr[i];
        }
        if(n==1){
            cout<<"YES"<<endl;
        }
        else{
            avg = sum / n;
            int i = 0,j= n-1;
            while(i<=j){
                if(arr[i]>avg){
                    if(temp>=0){
                        temp+=(arr[i]-avg);
                        flag2=1;
                    }
                    arr[i]=avg;
                }
                else{
                    if(temp>=0){
                        temp-=(avg-arr[i]);
                        flag2=1;
                    }
                    arr[i]=avg;
                }
                i++;
            }
            for(int i = 0;i<n;i++){
                if(arr[i]!=avg){
                    flag = 1;
                    break;
                }
            }
            if(!flag && temp==0 && flag2) cout<<"YES"<<endl;
            else if(flag==0 || temp!=0){
                cout<<"NO"<<endl;
            }
        }
        
    }   
}