/**
 * @file geometricSum.cpp
 * @brief Calculates the sum of a geometric series using recursion.
 */

#include <iostream>
#include <cmath>

/**
 * @brief Calculates the sum of a geometric series using recursion.
 * 
 * This function calculates the sum of a geometric series up to the kth term using recursion.
 * 
 * @param k The number of terms in the series.
 * @return The sum of the geometric series up to the kth term.
 */
double gSum(int k) {
    /**< Base case */
    if (k == 0) {
        return 1; /**< Base case: Sum of the geometric series with 0 terms is 1. */
    }

    /**< Recursive case */
    double smallAns = gSum(k - 1);

    /**< Calculation */
    double ans = smallAns + 1 / pow(2, k); /**< Calculate the sum of the geometric series up to the kth term. */

    return ans;
}

/**
 * @brief Main function to demonstrate the calculation of geometric series using recursion.
 * @return 0 on successful execution.
 */
int main(void) {
    int k = 3; /**< Number of terms in the geometric series. */
    double sum = gSum(k); /**< Calculate the sum of the geometric series up to the kth term. */
    std::cout << "Sum of the Geometric Series: " << sum; /**< Print the sum of the geometric series. */

    return 0;
}
