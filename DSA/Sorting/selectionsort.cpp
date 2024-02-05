#include<bits/stdc++.h>
 
using namespace std;

void swap(int &x,int &y){
    int temp = x;
    x = y;
    y = temp;
    return;
}

void selection_sort(int arr[],int n){
    for(int i = 0;i<=n-2;i++){
        int mini = i;
        for(int j = i;j<=n-1;j++){
            if(arr[j]<arr[mini]){
                mini = j;
            }
        }
        swap(arr[i],arr[mini]);
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int arr [] {13,46,24,52,20,9};
    selection_sort(arr,6);
    for(int i = 0;i<6;i++){
        cout<<arr[i]<<endl;
    }
}