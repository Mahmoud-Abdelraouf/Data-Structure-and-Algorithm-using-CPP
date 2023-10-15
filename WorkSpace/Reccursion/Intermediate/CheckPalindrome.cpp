/**
 * @file checkPal.cpp
 * @brief Checks if an array is a palindrome using recursion.
 */

#include <iostream>

/**
 * @brief Checks if a subarray of integers is a palindrome using recursion.
 * 
 * This function checks if the given subarray of integers is a palindrome.
 * 
 * @param a The array of integers.
 * @param s The starting index of the subarray.
 * @param e The ending index of the subarray.
 * @return True if the subarray is a palindrome, false otherwise.
 */
bool checkPal(int a[], int s, int e) {
    /**< Base case */
    if (s >= e) {
        return true; /**< Empty or single-element subarray is a palindrome. */
    }

    /**< Check if the first and last elements match */
    if (a[s] == a[e]) {
        return checkPal(a, s + 1, e - 1); /**< Recur with the next subarray. */
    } else {
        return false; /**< Mismatch indicates non-palindrome. */
    }
}

/**
 * @brief Main function to demonstrate checking if an array is a palindrome using recursion.
 * @return 0 on successful execution.
 */
int main(void) {
    int arr[] = {1, 2, 3, 2, 1}; /**< Example array of integers: A palindrome. */
    int n = sizeof(arr) / sizeof(arr[0]); /**< Calculate the number of elements in the array. */

    bool isPalindrome = checkPal(arr, 0, n - 1); /**< Check if the entire array is a palindrome. */
    
    if (isPalindrome) {
        std::cout << "The array is a palindrome.";
    } else {
        std::cout << "The array is not a palindrome.";
    }

    return 0;
}
