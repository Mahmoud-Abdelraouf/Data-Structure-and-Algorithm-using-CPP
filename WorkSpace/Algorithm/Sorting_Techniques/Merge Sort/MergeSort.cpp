/**
 * @file mergeSort.cpp
 * @brief Implements the merge sort algorithm using recursion.
 */

#include <iostream>

using namespace std;

/**
 * @brief Merges two sorted arrays into a single sorted array.
 * 
 * @param a The original array containing two sorted halves to be merged.
 * @param s The starting index of the first half.
 * @param e The ending index of the second half.
 */
void merge(int *a, int s, int e) {
    int mid = (s + e) / 2; /**< Calculate the middle index of the range. */
    int i = s; /**< Initialize index for the first half of the array. */
    int j = mid + 1; /**< Initialize index for the second half of the array. */
    int k = 0; /**< Initialize index for the temporary array. */

    /**< Dynamically allocate memory for the temporary array based on the size of the subarray */ 
    int *temp = new int[e - s + 1];

    /**< Merge elements from the two halves into the temporary array */ 
    while (i <= mid && j <= e) {
        if (a[i] < a[j]) {
            temp[k++] = a[i++]; /**< Place the smaller element into the temporary array. */
        } else {
            temp[k++] = a[j++]; /**< Place the smaller element into the temporary array. */
        }
    }

    /**< Copy remaining elements from the first half, if any */ 
    while (i <= mid) {
        temp[k++] = a[i++];
    }

    /**< Copy remaining elements from the second half, if any */ 
    while (j <= e) {
        temp[k++] = a[j++];
    }

    /**< Copy elements back from the temporary array to the original array */ 
    for (int p = s; p <= e; p++) {
        a[p] = temp[p - s]; /**< Copy elements back to the original array. */
    }

    /**< Deallocate the dynamically allocated memory to avoid memory leaks */ 
    delete[] temp;
}

/**
 * @brief Sorts an array using the merge sort algorithm.
 * 
 * @param a The array to be sorted.
 * @param s The starting index of the range in the array.
 * @param e The ending index of the range in the array.
 */
void mergeSort(int a[], int s, int e) {
    /**< Base case: If the array has one or zero elements, it is already sorted. */
    if (s >= e) {
        return;
    }

    /**< Divide the array into two halves. */
    int mid = (s + e) / 2;

    /**< Recursively sort the first and second halves. */
    mergeSort(a, s, mid);
    mergeSort(a, mid + 1, e);

    /**< Merge the sorted halves. */
    merge(a, s, e);
}

/**
 * @brief Main function to demonstrate the merge sort algorithm.
 * @return 0 on successful execution.
 */
int main(void) {
    /**< Example unsorted array. */
    int arr[] = {12, 11, 13, 5, 6, 7};
    /**< Calculate the number of elements in the array. */
    int n = sizeof(arr) / sizeof(arr[0]);

    /**< Sort the array using merge sort. */
    mergeSort(arr, 0, n - 1);

    /**< Print the sorted array. */
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
