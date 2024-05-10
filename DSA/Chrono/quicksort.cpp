#include<bits/stdc++.h>
#include<chrono>
 
using namespace std;


int partition(int A[],int l,int h)
{
    int pivot;

    // Middle Element Pivoting
    int mid = (l+h)/2;
    pivot = A[mid];
 
    int i=l,j=h;
    
    do
    {
        do{
            i++;
        }
        while(A[i]<=pivot);
        do{
            j--;
        }
        while(A[j]>pivot);
        
        if(i<j)swap(A[i],A[j]);
    }
    while(i<j);
    
    swap(A[l],A[j]);
    return j;
}
void QuickSort(int A[],int l,int h)
{
    int j;
    if(h==1){
        return;
    }
    if(l<h)
    {
        j=partition(A,l,h);
        QuickSort(A,l,j);
        QuickSort(A,j+1,h);
    }
} 

int QuickSortbase(int arr[], int size){

    int temp[size];
    for(int i = 0;i<size;i++){
        temp[i] = arr[i];
    }

    auto start = chrono::high_resolution_clock::now();

    QuickSort(temp,0,size-1);

    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();

    return duration;
}
 
