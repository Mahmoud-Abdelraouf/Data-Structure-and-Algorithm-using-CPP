/**
 * @file factorial.cpp
 * @brief Calculates the factorial of a given number using recursion.
 */

#include <iostream>

/**
 * @brief Calculates the factorial of a non-negative integer.
 * 
 * This recursive function calculates the factorial of a non-negative integer.
 * If the input is negative, it returns -1.
 * 
 * @param n The non-negative integer for which factorial is to be calculated.
 * @return Factorial of n if n is non-negative, -1 otherwise.
 */
int fact(int n) {
    
    if (n < 0) {
        return -1; /**< Invalid input: Negative number. */
    }

    /**< Base case 1st step */
    if (n == 0) {
        return 1; /**< Base case: Factorial of 0 is 1. */
    }

    /**< 2nd step assumption Recursive case */
    int smallAns = fact(n - 1);
    
    /**< 3rd step calculation */
    int ans  = n * smallAns; 
    
    return ans;
}

/**
 * @brief Main function to calculate the factorial of a number.
 * @return 0 on successful execution.
 */
int main(void) {
    int factNumber = 0;
    std::cout << "Enter the number you want to calculate its factorial: ";
    std::cin >> factNumber;

    int factorial = fact(factNumber);
    std::cout << "The factorial of " << factNumber << " is: " << factorial;

    return 0;
}
