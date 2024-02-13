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
        for(int i = 0;i<n;i++){
            cin>>arr[i];
        }
        int i = 0,j=n-1;
        while(i<j){
            if(arr[i]==arr[i+1]){
                i++;
            }
            else{
                //i++;
                break;
            }
        }
        if(i>=j){
            cout<<0<<endl;
            continue;
        }
        while(i<=j){
            if(arr[j]==arr[j-1]){
                j--;
            }
            else{
                //j--;
                break;
            }
        }
        if(arr[i]==arr[j]){
            i++;
            j--;
        }
        else{
            if(i>=(n-j-1)){
                i++;
                j = n-1;
            }
            else{
                j--;
                i=0;
            }
        }
        cout<<j-i+1<<endl;
    }   
}