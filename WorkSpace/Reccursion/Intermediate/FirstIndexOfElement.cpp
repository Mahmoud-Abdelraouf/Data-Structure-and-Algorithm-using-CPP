/**
 * @file firstIndex.cpp
 * @brief Finds the first occurrence index of a specific element in an array using recursion.
 */

#include <iostream>

/**
 * @brief Finds the first occurrence index of a specific element in an array using recursion.
 * 
 * This function finds the index of the first occurrence of the given element in the given array using recursion.
 * 
 * @param a The array of integers.
 * @param n The number of elements in the array.
 * @param x The element to search for.
 * @param i The current index being checked (initially set to 0).
 * @return The index of the first occurrence of the element, or -1 if the element is not found.
 */
int firstIndex(int a[], int n, int x, int i = 0) {
    /**< Base case */
    if (i == n) {
        return -1; /**< Element not found in the array. */
    }

    /**< Calculation */
    if (a[i] == x) {
        return i; /**< Element found, return the index. */
    }

    /**< Recursive case */
    return firstIndex(a, n, x, i + 1); /**< Search for the element in the remaining array. */
}

/**
 * @brief Main function to demonstrate finding the first occurrence index of an element in an array using recursion.
 * @return 0 on successful execution.
 */
int main(void) {
    int arr[] = {3, 2, 3, 2, 5}; /**< Example array of integers. */
    int n = sizeof(arr) / sizeof(arr[0]); /**< Calculate the number of elements in the array. */
    int x = 2; /**< Element to search for. */

    int index = firstIndex(arr, n, x); /**< Find the index of the first occurrence of the element. */
    
    if (index != -1) {
        std::cout << "Element " << x << " found at first index: " << index;
    } else {
        std::cout << "Element " << x << " not found in the array.";
    }

    return 0;
}
