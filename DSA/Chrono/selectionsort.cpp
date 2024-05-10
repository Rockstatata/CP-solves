#include<bits/stdc++.h>
#include<chrono>
 
using namespace std;

void SelectionSort(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        int mini=i;
        for(int j=i+1;j<size;j++)
        {
            if(arr[mini]>arr[j])
            {
                mini=j;
            }
        }
        if(mini!=i) // If mini==i then no need to swap the elements
        {
            swap(arr[mini],arr[i]);
        }
    }
}

int SelectionSortbase(int arr[], int size){

    int temp[size];
    for(int i = 0;i<size;i++){
        temp[i] = arr[i];
    }

    auto start = chrono::high_resolution_clock::now();

    SelectionSort(temp,size);

    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();

    return duration;
}
 