#include<bits/stdc++.h>
 
using namespace std;


void heapify(int arr[], int N, int i)
{
    int largest = i;

    int l = 2 * i;

    int r = 2 * i + 1;

    if (l < N && arr[l] > arr[largest])
        largest = l;

    if (r < N && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, N, largest);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int H [] = {0,10,20,15,12,40,25,18};
    int size = sizeof(H)/sizeof(H[0]);
    int i = 0;
    for(i = (size/2 )-1;i>0;i--){
        heapify(H,size,i);
    }
    for(int i = 1;i<size;i++){
        cout<<H[i]<<" ";
    }
    cout<<endl;
}