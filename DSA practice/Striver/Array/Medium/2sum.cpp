#include<bits/stdc++.h>
 
using namespace std;

bool hashtwosum(int arr[],int n,int k){
    unordered_map<int,int>mp;
    for(int i = 0;i<n;i++){
        int rest = k-arr[i];
        if(mp.find(rest) != mp.end()){
            return true;
        }
        mp[arr[i]] = i;
    }
    return false;
}

bool twopointertwosum(int arr[], int n, int k){
    sort(arr,arr+n);
    int i = 0,j=n-1;
    while(i<j){
        int res = arr[i]+arr[j];
        if(res==k){
            return true;
        }
        else if(res>k){
            j--;
        }
        else{
            i++;
        }   
    }
    return false;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int arr [] = {2,6,5,8,11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 14;
    cout<<twopointertwosum(arr,n,k)<<endl;
}