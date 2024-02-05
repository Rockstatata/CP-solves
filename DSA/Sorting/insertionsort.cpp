#include<bits/stdc++.h>
 
using namespace std;

void swap(int &x,int &y){
    int temp = x;
    x = y;
    y = temp;
    return;
}

void insertion_sort(int arr[], int n){
    for(int i = 0;i<=n-1;i++){
        int j = i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int arr [] {13,46,24,52,20,9};
    insertion_sort(arr,6);
    for(int i = 0;i<6;i++){
        cout<<arr[i]<<endl;
    }
}