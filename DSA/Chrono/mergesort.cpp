#include<bits/stdc++.h>
#include<chrono>
 
using namespace std;

void merge(vector<int>&arr,int lb,int mid, int ub)
{
    int i=lb;
    int j=mid+1;
    int k=lb;
    int b[lb+ub+1];
    while(i<=mid && j<=ub)
    {
        if(arr[i]<=arr[j])
        {
            b[k]=arr[i];
            i++;
        }
        else
        {
            b[k]=arr[j];
            j++;
        }
        k++;
    }
    if(i>mid)
    {
        while(j<=ub)
        {
            b[k]=arr[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<=mid)
        {
            b[k]=arr[i];
            i++;
            k++;
        }
    }
    for(k=lb;k<=ub;k++)
    {
        arr[k]=b[k];
    }
}
void MergeSort(vector<int>&arr,int lb, int ub)
{
    if(lb<ub)
    {
        int mid=(lb+ub)/2;
        MergeSort(arr,lb,mid);
        MergeSort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
    }
}

int MergeSortbase(vector<int>&arr, int size){

    vector<int>temp = arr;

    auto start = chrono::high_resolution_clock::now();

    MergeSort(temp,0,size-1);

    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();

    return duration;
}
 
