/**
 * @file countZeros.cpp
 * @brief Counts the number of zeros in a given integer using recursion.
 */

#include <iostream>

/**
 * @brief Counts the number of zeros in a given integer using recursion.
 * 
 * This function calculates the number of zeros in the provided integer using recursion.
 * 
 * @param n The integer in which zeros need to be counted.
 * @return The number of zeros in the integer.
 */
int countZeros(int n) {
    /**< Base case */
    if (n == 0) {
        return 0; /**< Base case: No zeros in 0. */
    }

    /**< Recursive case */
    int smallOut = countZeros(n / 10);

    /**< Calculation */
    int lastDigit = n % 10;
    if (lastDigit == 0) {
        return smallOut + 1; /**< Increment count if the last digit is 0. */
    } else {
        return smallOut;
    }
}

/**
 * @brief Main function to count zeros in an integer using recursion.
 * @return 0 on successful execution.
 */
int main(void) {
    int zeros = countZeros(1023505); /**< Calculate the number of zeros in the given integer. */
    std::cout << "Number of Zeros: " << zeros; /**< Print the count of zeros. */

    return 0;
}
