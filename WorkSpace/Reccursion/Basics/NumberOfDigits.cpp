/**
 * @file digitCount.cpp
 * @brief Counts the number of digits in a given integer using recursion.
 */

#include <iostream>

/**
 * @brief Counts the number of digits in a given integer using recursion.
 * 
 * This function counts the number of digits in the provided integer using recursion.
 * 
 * @param n The integer for which digits need to be counted.
 * @return The number of digits in the integer.
 */
int countDigits(int n) {
    /**< Base case */
    if (n == 0) {
        return 0; /**< Base case: No digits for 0. */
    }

    /**< Recursive case */
    int smallOutput = countDigits(n / 10);

    /**< Calculation */
    int ans = smallOutput + 1; /**< Add 1 for the current digit. */

    return ans;
}

/**
 * @brief Main function to demonstrate counting digits using recursion.
 * @return 0 on successful execution.
 */
int main(void) {
    int num = 45036;
    int digitCount = countDigits(num);
    
    std::cout << "Number of digits in " << num << " is: " << digitCount;

    return 0;
}
