#pragma once

#include <cstdlib>
#include <ctime>
#include "bubblesort.cpp"
#include "insertionsort.cpp"
#include "selectionsort.cpp"
#include "radixsort.cpp"
#include "countsort.cpp"
#include "heapsort.cpp"
#include "quicksort.cpp"
#include "mergesort.cpp"


using namespace std;

vector<int> generateRandomArray(int size)
{
    vector<int> arr(size);
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % 1000; 
    }
    return arr;
}

 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    srand(time(0));
    vector<int> inputsizes = {1000,5000,10000,15000,25000,35000,50000,65000,75000,85000};

    for(int sizes:inputsizes){
        vector<int> arr = generateRandomArray(sizes);
    
        int bubbletime = BubbleSortbase(arr,sizes);
        int insertiontime = InsertionSortbase(arr,sizes);
        int selectiontime = SelectionSortbase(arr,sizes);
        int quicktime = QuickSortbase(arr,sizes);
        int mergetime = MergeSortbase(arr,sizes);
        int heaptime = HeapSortbase(arr,sizes);
        int counttime = CountSortbase(arr,sizes);
        int radixtime = RadixSortbase(arr,sizes);
        

        cout<<"Elements: "<<sizes<<endl<<endl;
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