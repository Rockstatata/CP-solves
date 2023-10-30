#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int len;
        cin>>len;
        int arr[len];
        for(int i = 0;i<len;i++){
            cin>>arr[i];
        }
        int &ref = *min_element(arr,arr+len);
        ref++;
        long long int mult = 1;
        for(int i = 0;i<len;i++){
            mult*=arr[i];
        }
        cout<<mult<<endl;
    }   
}