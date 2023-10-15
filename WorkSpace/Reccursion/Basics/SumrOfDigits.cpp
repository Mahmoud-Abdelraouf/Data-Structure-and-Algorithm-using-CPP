/**
 * @file sumDigits.cpp
 * @brief Calculates the sum of digits of a given number using recursion.
 */

#include <iostream>

/**
 * @brief Calculates the sum of digits of a given integer using recursion.
 * 
 * This function calculates the sum of digits in the provided integer using recursion.
 * 
 * @param n The integer for which sum of digits need to be calculated.
 * @return The sum of digits in the integer.
 */
int sumDigit(int n) {
    /**< Base case */
    if (n == 0) {
        return 0; /**< Base case: No digits for 0. */
    }

    /**< Recursive case */
    int smallAns = sumDigit(n / 10);

    /**< Calculation */
    int lastDigit = n % 10;
    int ans = smallAns + lastDigit;

    return ans;
}

/**
 * @brief Main function to demonstrate summing digits using recursion.
 * @return 0 on successful execution.
 */
int main(void) {
    int num = 123456;
    int digitSum = sumDigit(num);
    
    std::cout << "Sum of digits in " << num << " is: " << digitSum;

    return 0;
}
