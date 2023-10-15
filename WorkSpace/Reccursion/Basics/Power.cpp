/**
 * @file power.cpp
 * @brief Calculates the power of a number using recursion and applies the Principle of Mathematical Induction (PMI).
 */

#include <iostream>

/**
 * @brief Calculates the power of a number using recursion.
 * 
 * This function calculates the power of a given base number raised to a given exponent using recursion.
 * It follows the Principle of Mathematical Induction (PMI) to recursively calculate the result.
 * 
 * @param x The base number.
 * @param n The exponent.
 * @return The result of x raised to the power of n.
 */
int power(int x, int n) {
    /**< Base case */
    if (n == 0) {
        return 1; /**< Base case: Any number raised to the power of 0 is 1. */
    }

    /**< Recursive case */
    int smallOutput = power(x, n - 1);

    /**< Calculation */
    int ans = x * smallOutput; /**< Apply PMI by multiplying the base with the result of the smaller problem. */

    return ans;
}

/**
 * @brief Main function to calculate the power of a number using PMI.
 * @return 0 on successful execution.
 */
int main(void) {
    int number = 0, powerNo = 0;

    std::cout << "Enter the Base Number: ";
    std::cin >> number;

    std::cout << "Enter the Exponent: ";
    std::cin >> powerNo;

    int result = power(number, powerNo);
    std::cout << "The Result: " << number << " ^ " << powerNo << " = " << result;

    return 0;
}
