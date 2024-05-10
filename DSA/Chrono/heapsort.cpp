#include<bits/stdc++.h>
#include<chrono>
 
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void HeapSort(int arr[], int size)
{
    
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);


    for (int i = size - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);

        
        heapify(arr, i, 0);
    }
}

int HeapSortbase(int arr[], int size){

    int temp[size];
    for(int i = 0;i<size;i++){
        temp[i] = arr[i];
    }

    auto start = chrono::high_resolution_clock::now();

    HeapSort(temp,size);

    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();

    return duration;
}
 