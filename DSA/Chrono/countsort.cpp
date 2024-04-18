#include<bits/stdc++.h>
#include<chrono>
 
using namespace std;

void CountSort(vector<int>&array, int size)
{
    int max = array[0];

    for (int i = 1; i < size; i++)  // Find the largest element of the array
    {
        if (array[i] > max)
            max = array[i];
    }
    vector<int> count(max + 1, 0), output(size);
    
    for (int i = 0; i < size; i++)  // Store the count of each element
    {
        count[array[i]]++;
    }

    for (int i = 1; i <= max; i++)  // Store the cummulative count of each array
    {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) // Find the index of each element of the original array in count array, and
                                        // place the elements in output array
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    for (int i = 0; i < size; i++)
    {
        array[i] = output[i];
    }
}

int CountSortbase(vector<int>&arr, int size){

    vector<int>temp = arr;

    auto start = chrono::high_resolution_clock::now();

    CountSort(temp,size);

    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();

    return duration;
}
 
