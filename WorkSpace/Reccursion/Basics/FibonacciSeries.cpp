/**
 * @file fibonacci.cpp
 * @brief Generates Fibonacci series using recursion based on mathematical induction.
 */

#include <iostream>

/**
 * @brief Calculates the Fibonacci number using recursion.
 * 
 * This function calculates the Fibonacci number at the given index using
 * recursion and the principle of mathematical induction.
 * 
 * @param n The index of the Fibonacci number to be calculated.
 * @return The Fibonacci number at index n.
 */
int fib(int n) {
    /**< Base case */
    if (n == 0) {
        return 0; /**< Base case: Fibonacci(0) = 0. */
    }
    if (n == 1) {
        return 1; /**< Base case: Fibonacci(1) = 1. */
    }

    /**< Recursive case */
    int smallOut1 = fib(n - 1);
    int smallOut2 = fib(n - 2);

    /**< Calculation */
    int ans = smallOut1 + smallOut2;

    return ans;
}

/**
 * @brief Main function to generate Fibonacci series using recursion.
 * @return 0 on successful execution.
 */
int main(void) {
    int fibIndex = 0;
    std::cout << "Enter the index (n) of the Fibonacci number you want to know: ";
    std::cin >> fibIndex;
    int fibNo = fib(fibIndex);
    std::cout << "The Fibonacci number at index " << fibIndex << " is: " << fibNo;

    return 0;
}
