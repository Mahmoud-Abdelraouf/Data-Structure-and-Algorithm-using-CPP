/**
 * @file printNumbers.cpp
 * @brief Demonstrates recursive printing of numbers from 1 to n.
 */

#include <iostream>

/**
 * @brief Recursively prints numbers from 1 to n in ascending order.
 * 
 * This function prints numbers from 1 to n using recursion in ascending order.
 * 
 * @param n The number up to which numbers need to be printed.
 */
void printAscending(int n) {
    /**< Base case */
    if (n == 0) {
        return; /**< Base case: Stop recursion when n is 0. */
    }

    /**< Recursive case */
    printAscending(n - 1); /**< 1 2 3 ..... n-2 n-1 */

    /**< Calculation */
    std::cout << n << "\t"; /**< Print the current number followed by a tab. */
}

/**
 * @brief Recursively prints numbers from 1 to n in descending order.
 * 
 * This function prints numbers from 1 to n using recursion in descending order.
 * 
 * @param n The number up to which numbers need to be printed.
 */
void printDescending(int n) {
    /**< Base case */
    if (n == 0) {
        return; /**< Base case: Stop recursion when n is 0. */
    }

    /**< Calculation */
    std::cout << n << "\t"; /**< Print the current number followed by a tab. */

    /**< Recursive case */
    printDescending(n - 1); /**< n-1 n-2 n-3 ..... 2 1 */
}

/**
 * @brief Main function to demonstrate printing numbers using recursion.
 * @return 0 on successful execution.
 */
int main(void) {
    std::cout << "Ascending Order:" << std::endl;
    printAscending(10); /**< Print numbers from 1 to 10 in ascending order. */

    std::cout << std::endl;

    std::cout << "Descending Order:" << std::endl;
    printDescending(10); /**< Print numbers from 1 to 10 in descending order. */

    return 0;
}
