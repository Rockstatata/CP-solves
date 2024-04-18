#include<bits/stdc++.h>
#include<chrono>
 
using namespace std;

void BubbleSort(vector<int>&arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < size - 1 - i; j++) // No need to traverse the whole array if the remaining elements are sorted
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j],arr[j+1]);
                flag = 1;
            }
        }
        if (flag == 0) //  If no swapping is done, that means that the array is already sorted
        {
            break;
        }
    }
}

int BubbleSortbase(vector<int>&arr, int size){
    
    vector<int>temp = arr;

    auto start = chrono::high_resolution_clock::now();

    BubbleSort(temp,size);

    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();

    return duration;
}
 
