#include<bits/stdc++.h>
 
using namespace std;

void countsort(int arr[],int n){
    int count[3] = {0};
    for(int i = 0;i<n;i++){
        count[arr[i]]++;
    }
    int i = 0,j=0;
    while(i<3 && j<n){
        if(count[i]!=0){
            arr[j++]=i;
            count[i]--;
        }
        else{
            i++;
        }
    }
}

void dutchnationalflag(int arr[],int n){
    int low=0,mid=0,high=n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[high],arr[mid]);
            high--;
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int arr [] = {2,0,2,1,1,0};
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    //countsort(arr,size);
    dutchnationalflag(arr,size);
    for(int i = 0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}