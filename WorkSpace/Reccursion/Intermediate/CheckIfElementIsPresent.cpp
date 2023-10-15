/**
 * @file arraySearch.cpp
 * @brief Checks if a specific element is present in an array using recursion.
 */

#include <iostream>

/**
 * @brief Checks if a specific element is present in an array using recursion (first implementation).
 * 
 * This function checks if the given element is present in the given array using recursion.
 * 
 * @param a The array of integers.
 * @param n The number of elements in the array.
 * @param x The element to search for.
 * @return True if the element is present, false otherwise.
 */
bool isPresent1(int a[], int n, int x) {
    /**< Base case */
    if (n == 0) {
        return false; /**< Base case: Element not found in an empty array. */
    }

    /**< Calculation */
    if (a[0] == x) {
        return true; /**< Element found at the first position. */
    }

    /**< Recursive case */
    return isPresent1(a + 1, n - 1, x); /**< Search for the element in the smaller array. */
}

/**
 * @brief Checks if a specific element is present in an array using recursion (second implementation).
 * 
 * This function checks if the given element is present in the given array using recursion.
 * 
 * @param a The array of integers.
 * @param n The number of elements in the array.
 * @param x The element to search for.
 * @return True if the element is present, false otherwise.
 */
bool isPresent2(int a[], int n, int x) {
    /**< Base case */
    if (n == 0) {
        return false; /**< Base case: Element not found in an empty array. */
    }

    /**< Recursive case */
    bool rightArr = isPresent2(a + 1, n - 1, x); /**< Search for the element in the smaller array. */

    if (rightArr) {
        return true; /**< If found in the smaller array, return true. */
    }

    /**< Check the current element */
    if (a[0] == x) {
        return true; /**< Element found at the current position. */
    } else {
        return false; /**< Element not found in the current position. */
    }
}

/**
 * @brief Main function to demonstrate searching for an element in an array using recursion.
 * @return 0 on successful execution.
 */
int main(void) {
    int arr[] = {1, 2, 3, 4, 5}; /**< Example array of integers. */
    int n = sizeof(arr) / sizeof(arr[0]); /**< Calculate the number of elements in the array. */
    int x = 15; /**< Element to search for. */

    bool found1 = isPresent1(arr, n, x); /**< Check if the element is present in the array (first implementation). */
    bool found2 = isPresent2(arr, n, x); /**< Check if the element is present in the array (second implementation). */

    if (found1) {
        std::cout << "Element " << x << " is present in the array (First implementation).";
    } else {
        std::cout << "Element " << x << " is not present in the array (First implementation).";
    }

    std::cout << std::endl;

    if (found2) {
        std::cout << "Element " << x << " is present in the array (Second implementation).";
    } else {
        std::cout << "Element " << x << " is not present in the array (Second implementation).";
    }

    return 0;
}
