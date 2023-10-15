/**
 * @file multiplication.cpp
 * @brief Multiplies two integers using recursion.
 */

#include <iostream>

/**
 * @brief Calculates the product of two integers using recursion.
 * 
 * This function calculates the product of two integers m and n using recursion.
 * 
 * @param m The first integer.
 * @param n The second integer.
 * @return The product of m and n.
 */
int multiply(int m, int n) {
    /**< Base case */
    if (n == 0) {
        return 0; /**< Base case: Any number multiplied by 0 is 0. */
    }

    /**< Recursive case */
    int smallAns = multiply(m, n - 1);

    /**< Calculation */
    return smallAns + m; /**< Multiply m by (n - 1) and add m to the result. */
}

/**
 * @brief Main function to demonstrate multiplication using recursion.
 * @return 0 on successful execution.
 */
int main() {
    int result = multiply(5, 3); /**< Calculate the product of 5 and 3 using recursion. */
    std::cout << "The Result: " << result; /**< Print the result. */

    return 0;
}
