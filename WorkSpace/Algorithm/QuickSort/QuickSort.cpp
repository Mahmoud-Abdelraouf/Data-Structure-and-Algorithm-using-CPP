/**
 * @file quickSort.cpp
 * @brief Implements the QuickSort algorithm using recursion.
 */

#include<iostream>
using namespace std;

/**
 * @brief Partitions the array into two subarrays and returns the index of the pivot element.
 * 
 * @param a The array to be partitioned.
 * @param s The starting index of the subarray to be partitioned.
 * @param e The ending index of the subarray to be partitioned.
 * @return The index of the pivot element after partitioning.
 */
int partition(int a[], int s, int e) {
    int i = s; /**< Initialize variable 'i' to the starting index of the subarray. */
    int pivot = a[e]; /**< Choose the last element of the subarray as the pivot element. */
    for (int j = s; j <= e - 1; j++) { /**< Iterate through the subarray from start to end-1. */
        if (a[j] < pivot) { /**< If the current element is less than the pivot element. */
            swap(a[i], a[j]); /**< Swap the current element with the element at index 'i' and move 'i' to the right. */
            i++; /**< Move 'i' to the right to maintain the elements smaller than the pivot to the left of 'i'. */
        }
    }
    swap(a[i], a[e]); /**< Swap the pivot element with the element at index 'i' to place the pivot in its correct position. */
    return i; /**< Return the index of the pivot element after partitioning. */
}

/**
 * @brief Sorts an array using the QuickSort algorithm.
 * 
 * @param a The array to be sorted.
 * @param s The starting index of the subarray to be sorted.
 * @param e The ending index of the subarray to be sorted.
 */
void quickSort(int a[], int s, int e) {
    /**< Base case: If the subarray has one or zero elements, it is already sorted */ 
    if (s >= e) {
        return;
    }
    /**< Partition the subarray and get the index of the pivot element */ 
    int p = partition(a, s, e);
    // Recursively sort the subarrays before and after the pivot element
    quickSort(a, s, p - 1);
    quickSort(a, p + 1, e);
}

/**
 * @brief Main function to demonstrate the QuickSort algorithm.
 * @return 0 on successful execution.
 */
int main() {
    int arr[] = {2, 1, 3, 4, 5, 7, -2}; // Example unsorted array
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array

    // Sort the array using QuickSort
    quickSort(arr, 0, n - 1);

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
