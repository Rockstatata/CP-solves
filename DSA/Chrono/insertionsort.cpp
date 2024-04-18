#include<bits/stdc++.h>
#include<chrono>
 
using namespace std;

void InsertionSort(vector<int>&arr,int size)
{
    int j=0;
    for(int i=1;i<size;i++)
    {
        int temp=arr[i];
        j=i-1;
        while(j>0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}

int InsertionSortbase(vector<int>&arr, int size){

    vector<int>temp = arr;

    auto start = chrono::high_resolution_clock::now();

    InsertionSort(temp,size);

    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();

    return duration;
}
 
