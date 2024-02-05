#include<bits/stdc++.h>
 
using namespace std;

void swap(int &x,int &y){
    int temp = x;
    x = y;
    y = temp;
    return;
}

void bubble_sort(int arr[],int n){
    for(int i = n-1;i>=0;i--){
        bool didswap = false;
        for(int j = 0;j<=i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                didswap = true;
            }
        }
        if(!didswap){
            break;
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int arr [] {13,46,24,52,20,9};
    bubble_sort(arr,6);
    for(int i = 0;i<6;i++){
        cout<<arr[i]<<endl;
    }
}