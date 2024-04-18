#include<bits/stdc++.h>
#include<chrono>
 
using namespace std;

void countingSort(vector<int>&arr, int size, int place)
{
    const int max = 10;
    vector<int> count(max,0),output(size);

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


void RadixSort(vector<int>&arr, int size)
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

int RadixSortbase(vector<int>&arr, int size){

    vector<int>temp = arr;

    auto start = chrono::high_resolution_clock::now();

    RadixSort(temp,size);

    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();

    return duration;
}
 
