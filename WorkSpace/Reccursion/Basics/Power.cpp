/**
 * @file power.cpp
 * @brief Calculates the power of a number using recursion.
 */

#include <iostream>

/**
 * @brief Calculates the power of a number using recursion.
 * 
 * This function calculates the power of a given number raised to a given exponent using recursion.
 * 
 * @param x The base number.
 * @param n The exponent.
 * @return The result of x raised to the power of n.
 */
int power(int x, int n) {
    /**< Base case */
    if (n == 0) {
        return 1;
    }

    /**< Recursive case */
    int smallOutput = power(x, n - 1);

    /**< Calculation */
    int ans = x * smallOutput;

    return ans;
}

/**
 * @brief Main function to calculate the power of a number.
 * @return 0 on successful execution.
 */
int main(void) {
    int number = 0, powerNo = 0;

    std::cout << "Enter the Number: ";
    std::cin >> number;

    std::cout << "Enter the power: ";
    std::cin >> powerNo;

    int result = power(number, powerNo);
    std::cout << "The Result: " << number << " ^ " << powerNo << " = " << result;

    return 0;
}
