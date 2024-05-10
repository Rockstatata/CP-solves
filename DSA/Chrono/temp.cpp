#include <bits/stdc++.h>
using namespace std;

// Function to generate input array for best, worst, or average case
void generateInput(vector<float> &arr, int size, string caseType)
{
    if (caseType == "best")
    {
        for (int i = 0; i < size; i++)
            arr[i] = static_cast<float>(i + 1) / size; // Already sorted array
    }
    else if (caseType == "worst")
    {
        for (int i = 0; i < size; i++)
            arr[i] = static_cast<float>(size - i) / size; // Reverse sorted array
    }
    else if (caseType == "average")
    {
        for (int i = 0; i < size; i++)
            arr[i] = static_cast<float>(rand()) / RAND_MAX; // Random float values between 0 and 1
    }
}

// Insertion sort function to sort individual buckets
void insertionSort(vector<float> &bucket)
{
    for (size_t i = 1; i < bucket.size(); i++)
    {
        float key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key)
        {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

// Function to sort arr[] of size n using bucket sort
void bucketSort(vector<float> &arr)
{
    int n = arr.size();

    // Create n empty buckets
    vector<vector<float>> b(n);

    // Put array elements in different buckets
    for (int i = 0; i < n; i++)
    {
        int bi = static_cast<int>(n * arr[i]);
        b[bi].push_back(arr[i]);
    }

    // Sort individual buckets using insertion sort
    for (int i = 0; i < n; i++)
    {
        insertionSort(b[i]);
    }

    // Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        for (float num : b[i])
        {
            arr[index++] = num;
        }
    }
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    // Validate input
    while (size <= 0)
    {
        cout << "Please enter a positive integer for the size: ";
        cin.clear();                                         // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
        cin >> size;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

    vector<float> arr(size);

    cout << "Choose the case type (best, worst, average): ";
    string caseType;
    cin >> caseType;

    double total_time = 0;
    int num_runs = 10;

    for (int j = 0; j < num_runs; j++)
    {
        generateInput(arr, size, caseType); // Generate input array

        clock_t start = clock();
        bucketSort(arr); // Sort using Bucket Sort
        clock_t end = clock();

        double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6; // Convert to microseconds
        total_time += elapsed_time;

        cout << "Runtime for run " << j + 1 << ": " << elapsed_time << " microseconds\n";
    }

    double avg_time = total_time / num_runs;
    cout << "Average Runtime for " << caseType << " " << num_runs << " runs: " << avg_time << " microseconds\n";

    return 0;
}
