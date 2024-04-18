#include<bits/stdc++.h>
#include<chrono>
 
using namespace std;

int partition(vector<int>&arr,int lb,int ub)
{
    int pivot=arr[lb];  // Let pivot be the first element of the array
    int start=lb;
    int end=ub;
    while(start<end)
    {
        while(arr[start]<=pivot)
        {
            start++;    
        }
        while(arr[end]>pivot)
        {
            end--;
        }
        if(start<end)
        {
            swap(arr[start],arr[end]);
        }
    }
    swap(arr[lb],arr[end]);         
    return end;     
}

void QuickSort(vector<int>&arr,int lb,int ub)
{
    if(lb<ub)
    {
        int loc=partition(arr,lb,ub);
        QuickSort(arr,lb,loc-1);
        QuickSort(arr,loc+1,ub);
    }
}

int QuickSortbase(vector<int>&arr, int size){

    vector<int>temp = arr;

    auto start = chrono::high_resolution_clock::now();

    QuickSort(temp,0,size-1);

    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();

    return duration;
}
 
