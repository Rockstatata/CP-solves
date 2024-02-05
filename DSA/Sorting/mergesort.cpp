#include<bits/stdc++.h>
 
using namespace std;

void swap(int &x, int& y){
    int temp = x;
    x = y;
    y = temp;
    return;
}

void Merge(int A[], int l, int mid, int h){
    int i,j,k;
    int B[h+1];
    i = l, j = mid+1, k = l;
    while(i<=mid && j<=h){
        if(A[i]<A[j]){
            B[k++]= A[i++];
        }
        else{
            B[k++] = A[j++];
        }
    }

    for(;i<=mid;i++){
        B[k++]=A[i];
    }

    for(;j<=h;j++){
        B[k++] = A[j];
    }

    for(i=l;i<=h;i++){
        A[i]=B[i];
    }
}

void iterative_mergesort(int A[], int n){
    int p,i,l,mid,h;
    for(p=2;p<=n;p=p*2){
        for(i=0;(i+p-1)<n;i=i+p){
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            Merge(A,l,mid,h);
        }
    }

    if((p/2) <n){
        Merge(A,0,p/2 -1,n-1);
    }
}

void recursive_mergesort(int A[],int l, int h){
    if(l<h){
        int mid = (l+h)/2;
        recursive_mergesort(A,l,mid);
        recursive_mergesort(A,mid+1,h);
        Merge(A,l,mid,h);
    }
}

void display(int arr[],int n){
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int arr [] = {8,2,9,6,5,4,3,7,4};
    int n = 9;
    display(arr,n);
    // iterative_mergesort(arr,n);
    // display(arr,n);
    recursive_mergesort(arr,0,n-1);
    display(arr,n);
}