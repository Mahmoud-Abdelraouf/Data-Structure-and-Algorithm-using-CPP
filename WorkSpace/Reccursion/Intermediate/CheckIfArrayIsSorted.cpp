/**
 * @file isArraySorted.cpp
 * @brief Checks if an array is sorted in non-decreasing order using recursion.
 */

#include <iostream>

/**
 * @brief Checks if an array is sorted in non-decreasing order using recursion.
 * 
 * This function checks if the given integer array is sorted in non-decreasing order using recursion.
 * 
 * @param arr The integer array to be checked for sorting.
 * @param n The number of elements in the array.
 * @return True if the array is sorted in non-decreasing order, false otherwise.
 */
bool isArraySorted(int arr[], int n) {
    /**< Base case */
    if (n == 0 || n == 1) {
        return true; /**< Base case: An empty array or an array with one element is considered sorted. */
    }

    if (arr[0] > arr[1]) {
        return false; /**< Base case: If the first element is greater than the second, the array is not sorted. */
    }

    /**< Recursive case */
    bool isSmallerArraySorted = isArraySorted(arr + 1, n - 1);

    /**< Calculation */
    return isSmallerArraySorted; /**< Check if the smaller array is sorted, and propagate the result. */
}

/**
 * @brief Main function to demonstrate checking if an array is sorted using recursion.
 * @return 0 on successful execution.
 */
int main(void) {
    int arr[] = {1, 2, 3, 4, 5}; /**< Example array: Sorted in non-decreasing order. */
    int n = sizeof(arr) / sizeof(arr[0]);
    bool isSorted = isArraySorted(arr, n);
    if (isSorted) {
        std::cout << "The array is sorted in non-decreasing order.";
    } else {
        std::cout << "The array is not sorted in non-decreasing order.";
    }

    return 0;
}
