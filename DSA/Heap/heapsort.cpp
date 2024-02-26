#include<bits/stdc++.h>

using namespace std;

void insertheap(int H[],int n){
    int i = n,temp;
    temp = H[i];
    while(i>1 && temp > H[i/2]){
        H[i] = H[i/2];
        i = i/2;
    }
    H[i] = temp;
}
 
int deleteheap(int H[],int n){
    int i,j,temp,val;
    val = H[1];
    H[1] = H[n];
    H[n] = val;
    i = 1, j = i*2;
    while(j<n-1){
        if(H[j+1]>H[j]){
            j=j+1;
        }
        if(H[i]<H[j]){
            temp = H[i];
            H[i] = H[j];
            H[j] = temp;
            i = j;
            j = 2*j;
        }
        else break;
    }
    return val;
}

void heapsort(int H[],int size){
    for(int i = 2;i<size;i++){
        insertheap(H,i);
    }
    for(int i = size-1;i>1;i--){
        deleteheap(H,i);
    }
}

 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int H[] = {0,2,5,8,9,4,10,7};
    int size = sizeof(H)/sizeof(H[0]);
    // for(int i = 2;i<size;i++){
    //     insertheap(H,i);
    // }
    // for(int i = 0;i<size;i++){
    //     cout<<H[i]<<" ";
    // }
    // cout<<endl;
    // for(int i = 1;i<size;i++){
    //     int n = size-i;
    //     deleteheap(H,n);
    // }
    heapsort(H,size);
    for(int i = 1;i<size;i++){
        cout<<H[i]<<" ";
    }
    cout<<endl;
    
}