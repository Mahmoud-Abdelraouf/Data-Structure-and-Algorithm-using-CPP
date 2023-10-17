/**
 * @file countWays.cpp
 * @brief Calculates the number of ways to climb stairs using recursion.
 */

#include <iostream>

/**
 * @brief Calculates the number of ways to climb stairs using recursion.
 * 
 * This function calculates the number of ways to climb a staircase of size 'n', where
 * a person can climb 1, 2, or 3 steps at a time, using recursive approach.
 * 
 * @param n The number of steps in the staircase.
 * @return The number of ways to climb the staircase.
 */
int countWays(int n) {
    /**< Base cases: 0 steps or 1 step can be climbed in 1 way */
    if (n == 0 || n == 1) {
        return 1;
    }

    /**< Special case: 2 steps can be climbed in 2 ways */
    if (n == 2) {
        return 2;
    }

    /**< Recursive case: number of ways to climb n steps is the sum of ways to climb (n-1), (n-2), and (n-3) steps */
    int ans = countWays(n - 1) + countWays(n - 2) + countWays(n - 3);
    return ans;
}

/**
 * @brief Main function to demonstrate calculating the number of ways to climb stairs using recursion.
 * @return 0 on successful execution.
 */
int main(void) {
    int n;
    std::cout << "Enter the number of steps in the staircase: ";
    std::cin >> n; /**< Example number of steps in the staircase. */

    int ways = countWays(n); /**< Calculate the number of ways to climb the staircase. */

    std::cout << "Number of ways to climb " << n << " steps: " << ways;

    return 0;
}

