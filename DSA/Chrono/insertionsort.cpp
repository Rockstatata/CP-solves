#include<bits/stdc++.h>
#include<chrono>
 
using namespace std;

void InsertionSort(int arr[],int size)
{
    int j=0;
    for(int i=1;i<size;i++)
    {
        int tempo=arr[i];
        j=i-1;
        while(j>0 && arr[j]>tempo)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=tempo;
    }
}

int InsertionSortbase(int arr[], int size){

    int temp[size];
    for(int i = 0;i<size;i++){
        temp[i] = arr[i];
    }

    auto start = chrono::high_resolution_clock::now();

    InsertionSort(temp,size);

    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();

    return duration;
}
 
