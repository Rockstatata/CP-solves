#pragma once

#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "bubblesort.cpp"
#include "insertionsort.cpp"
#include "selectionsort.cpp"
#include "radixsort.cpp"
#include "countsort.cpp"
#include "heapsort.cpp"
#include "quicksort.cpp"
#include "mergesort.cpp"


using namespace std;

int arr[75000]; 

void generateWorstArray(int size)
{
    for (int i = 0; i < size; ++i)
    {
        arr[i] = (size*(int(log2(size)))) - i;
    }
}

void generateRandomArray(int size)
{
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % (size*(int(log2(size)))/2); 
    }
}

void generateBestArray(int size)
{
    for(int i = 0;i<size;i++){
        arr[i] = i;
    }
}



 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    srand(time(0));
    vector<int> inputsizes = {1000,5000,10000,15000,25000,35000,50000,65000,75000};
    vector<string> cases{"Best","Worst","Average"};
    for(int sizes:inputsizes){
        cout<<"Elements: "<<sizes<<endl<<endl;
        for(string cas: cases){
            cout<<cas<<" Case Scenario:\n\n";
            if(cas=="Best"){
                generateBestArray(sizes);
            }
            else if(cas == "Worst"){
                generateWorstArray(sizes);
            }
            else{
                generateRandomArray(sizes);
            }

            // Bubble Sort Averaging time in 20 runtimes
            int bubbletime = 0;
            for(int i = 0;i<20;i++){
                bubbletime += BubbleSortbase(arr,sizes);
            }
            bubbletime /=20;

            // Insertion Sort Averaging time in 20 runtimes
            int insertiontime = 0;
            for(int i = 0;i<20;i++){
                insertiontime += InsertionSortbase(arr,sizes);
            }
            insertiontime /=20;

            // Selection Sort Averaging time in 20 runtimes
            int selectiontime = 0;
            for(int i = 0;i<20;i++){
                selectiontime += SelectionSortbase(arr,sizes);
            }
            selectiontime /=20;

            // Quick Sort Averaging time in 20 runtimes
            int quicktime = 0;
            for(int i = 0;i<20;i++){
                quicktime += QuickSortbase(arr,sizes);
            }
            quicktime /=20;

            // Merge Sort Averaging time in 20 runtimes
            int mergetime = 0;
            for(int i = 0;i<20;i++){
                mergetime += MergeSortbase(arr,sizes);
            }
            mergetime /=20;

            // Heap Sort Averaging time in 20 runtimes
            int heaptime = 0;
            for(int i = 0;i<20;i++){
                heaptime += HeapSortbase(arr,sizes);
            }
            heaptime /=20;

            // Count Sort Averaging time in 20 runtimes
            int counttime = 0;
            for(int i = 0;i<20;i++){
                counttime += CountSortbase(arr,sizes);
            }
            counttime /=20;

            // Radix Sort Averaging time in 20 runtimes
            int radixtime = 0; 
            for(int i = 0;i<20;i++){
                radixtime += RadixSortbase(arr,sizes);
            }
            radixtime /=20;
            
            
            cout << "Bubble Sort Sorted " << sizes << " elements in " << bubbletime << " microseconds." << endl;
            cout << "Insertion Sort Sorted " << sizes << " elements in " << insertiontime << " microseconds." << endl;
            cout << "Selection Sort Sorted " << sizes << " elements in " << selectiontime << " microseconds." << endl;
            cout << "Quick Sort Sorted " << sizes << " elements in " << quicktime << " microseconds." << endl;
            cout << "Merge Sort Sorted " << sizes << " elements in " << mergetime << " microseconds." << endl;
            cout << "Heap Sort Sorted " << sizes << " elements in " << heaptime << " microseconds." << endl;
            cout << "Count Sort Sorted " << sizes << " elements in " << counttime << " microseconds." << endl;
            cout << "Radix Sort Sorted " << sizes << " elements in " << radixtime << " microseconds." << endl;
            cout<<endl;
        }
    }
}