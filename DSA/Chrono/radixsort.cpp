#include<bits/stdc++.h>
#include<chrono>
 
using namespace std;

void countingSort(int arr[], int size, int place)
{
    const int max = 10;
    int count [max] {0};
    int output [size];

    for (int i = 0; i < size; i++)
        count[(arr[i] / place) % 10]++; // Calculate count of elements

    for (int i = 1; i < max; i++)
        count[i] += count[i - 1];   // Calculate cumulative count

    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(arr[i] / place) % 10] - 1] = arr[i];  // Place the elements in sorted order
        count[(arr[i] / place) % 10]--;
    }
    for (int i = 0; i < size; i++)
        arr[i] = output[i];
}


void RadixSort(int arr[], int size)
{
    // Get maximum element
    int max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];
    // Apply counting sort to sort elements based on place value.
    for (int place = 1; max / place > 0; place *= 10)
        countingSort(arr, size, place);
}

int RadixSortbase(int arr[], int size){
    int temp[size];
    for(int i = 0;i<size;i++){
        temp[i] = arr[i];
    }

    auto start = chrono::high_resolution_clock::now();

    RadixSort(temp,size);

    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();

    return duration;
}


int main(){
    int arr[] = {1,4,5,6,3,2,5,6,2,6,7,2,9,78,53,3,34,24,3,245,31,65,43};
    int size = sizeof(arr)/sizeof(arr[0]);
    RadixSort(arr,size);
    
}
 
