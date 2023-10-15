/**
 * @file lastIndex.cpp
 * @brief Finds the last occurrence index of a specific element in an array using recursion.
 */

#include <iostream>

/**
 * @brief Finds the last occurrence index of a specific element in an array using recursion.
 * 
 * This function finds the index of the last occurrence of the given element in the given array using recursion.
 * 
 * @param a The array of integers.
 * @param n The number of elements in the array.
 * @param x The element to search for.
 * @param i The current index being checked (initially set to n - 1).
 * @return The index of the last occurrence of the element, or -3 if the element is not found.
 */
int lastIndex(int a[], int n, int x, int i) {
    /**< Base case */
    if (i == -1) {
        return -3; /**< Invalid initial index. */
    }

    /**< Calculation */
    if (a[i] == x) {
        return i; /**< Element found, return the index. */
    }

    /**< Recursive case */
    return lastIndex(a, n, x, i - 1); /**< Search for the element in the previous positions of the array. */
}

/**
 * @brief Overloaded function to find the last occurrence index of a specific element in an array using recursion.
 * 
 * This function overloads the lastIndex function to provide an alternative implementation.
 * 
 * @param a The array of integers.
 * @param n The number of elements in the array.
 * @param x The element to search for.
 * @return The index of the last occurrence of the element, or -3 if the element is not found.
 */
int lastIndex(int a[], int n, int x) {
    /**< Base case */
    if (n == 0) {
        return -3; /**< Invalid initial index for an empty array. */
    }

    /**< Calculation */
    if (a[n - 1] == x) {
        return n - 1 ; /**< Element found, return the index. */
    }

    /**< Recursive case */
    return lastIndex(a, n - 1, x); /**< Search for the element in the previous positions of the array. */
}

/**
 * @brief Main function to demonstrate finding the last occurrence index of an element in an array using recursion.
 * @return 0 on successful execution.
 */
int main(void) {
    int arr[] = {1, 2, 3, 4, 3, 5}; /**< Example array of integers. */
    int n = sizeof(arr) / sizeof(arr[0]); /**< Calculate the number of elements in the array. */
    int x = 10; /**< Element to search for. */

    int index = lastIndex(arr, n, x); /**< Find the index of the last occurrence of the element. */
    
    if (index != -3) {
        std::cout << "Element " << x << " found at last index: " << index;
    } else {
        std::cout << "Element " << x << " not found in the array.";
    }

    return 0;
}
