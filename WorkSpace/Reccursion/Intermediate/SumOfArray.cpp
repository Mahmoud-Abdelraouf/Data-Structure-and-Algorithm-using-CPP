/**
 * @file arraySum.cpp
 * @brief Calculates the sum of elements in an array using recursion.
 */

#include <iostream>

/**
 * @brief Calculates the sum of elements in an array using recursion.
 * 
 * This function calculates the sum of elements in the given array using recursion.
 * 
 * @param a The array of integers.
 * @param n The number of elements in the array.
 * @return The sum of elements in the array.
 */
int sumOfArray(int a[], int n) {
    /**< Base case */
    if (n == 0) {
        return 0; /**< Base case: Sum of an empty array is 0. */
    }

    /**< Recursive case */
    int sumOfSmallArray = sumOfArray(a + 1, n - 1);

    /**< Calculation */
    return a[0] + sumOfSmallArray; /**< Sum the current element with the sum of the smaller array. */
}

/**
 * @brief Main function to demonstrate the calculation of the sum of elements in an array using recursion.
 * @return 0 on successful execution.
 */
int main(void) {
    int arr[] = {1, 2, 3, 4, 5}; /**< Example array of integers. */
    int n = sizeof(arr) / sizeof(arr[0]); /**< Calculate the number of elements in the array. */

    int sum = sumOfArray(arr, n); /**< Calculate the sum of elements in the array. */
    std::cout << "Sum of the array elements: " << sum; /**< Print the sum of the array elements. */

    return 0;
}
