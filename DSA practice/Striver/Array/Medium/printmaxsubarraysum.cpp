#include<bits/stdc++.h>
 
using namespace std;

long long maxSubarraySum(int arr[], int n, int& l, int& h){
    long long sum= 0, max_sum=0, start=0;
    for(int i = 0;i<n;i++){
        if(sum==0){
            start = i;
        }
        sum+=arr[i];
        if(sum>=max_sum){
            max_sum = sum;
            h = i;
            l = start;
        } 
        if(sum<0){
            sum = 0;
        }
    }
    return max_sum;
}
 
int main(){
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, -6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i=0,j=0;
    long long maxSum = maxSubarraySum(arr, n, i, j);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    cout<<i<<" "<<j<<endl;
    for(i;i<=j;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}