/**
 * @file fibonacci.cpp
 * @brief Implements functions for Fibonacci number calculations using recursion and iteration.
 */

#include <iostream>
#include <chrono>

using namespace std;

/**
 * @brief Gets the current time in microseconds using the high_resolution_clock from the chrono library.
 * 
 * This function retrieves the current time using the high_resolution_clock, which provides the 
 * highest precision clock available on the system. It then calculates the time elapsed since the epoch
 * (typically January 1, 1970) in microseconds and returns the result.
 * 
 * @return The current time in microseconds.
 */
long long getTimeInMicrosecond() {
    auto currentTime = std::chrono::high_resolution_clock::now();
    auto timeSinceEpoch = currentTime.time_since_epoch();
    auto microSeconds = std::chrono::duration_cast<std::chrono::microseconds>(timeSinceEpoch).count();
    return microSeconds;
}

/**
 * @brief Calculates the Fibonacci number using recursion.
 * 
 * This function calculates the Fibonacci number at the given index using
 * recursion and the principle of mathematical induction.
 * 
 * @param n The index of the Fibonacci number to be calculated.
 * @return The Fibonacci number at index n.
 */
int fibRecursive(int n) {
    /**< Base case */
    if (n == 0) {
        return 0; /**< Base case: Fibonacci(0) = 0. */
    }
    if (n == 1) {
        return 1; /**< Base case: Fibonacci(1) = 1. */
    }

    /**< Recursive case */
    int smallOut1 = fibRecursive(n - 1);
    int smallOut2 = fibRecursive(n - 2);

    /**< Calculation */
    int ans = smallOut1 + smallOut2;

    return ans;
}

/**
 * @brief Calculates the Fibonacci number iteratively.
 * 
 * This function calculates the Fibonacci number at the given index using iteration.
 * 
 * @param n The index of the Fibonacci number to be calculated.
 * @return The Fibonacci number at index n.
 */
int fibIterative(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }

    int prev1 = 0; /**< Fibonacci(0) */
    int prev2 = 1; /**< Fibonacci(1) */
    int result = 0;

    for (int i = 2; i <= n; ++i) {
        result = prev1 + prev2;
        prev1 = prev2;
        prev2 = result;
    }

    return result;
}

/**
 * @brief Main function to calculate Fibonacci numbers and measure execution time.
 * 
 * This function prompts the user to enter the index of the Fibonacci number to be calculated.
 * It calculates the Fibonacci number both recursively and iteratively, measures the execution time for both methods,
 * and prints the results along with the execution times.
 * 
 * @return 0 on successful execution.
 */
int main() {
    // Array of Fibonacci indices to calculate
    int fibonacciIndices[] = {10, 20, 30, 40, 50};

    // Calculate and print Fibonacci numbers for each index
    for (int i = 0; i < sizeof(fibonacciIndices) / sizeof(fibonacciIndices[0]); ++i) {
        int fibIndex = fibonacciIndices[i];

        // Measure time for recursive Fibonacci calculation
        auto startRecursive = chrono::high_resolution_clock::now();
        int recursiveFib = fibRecursive(fibIndex);
        auto endRecursive = chrono::high_resolution_clock::now();
        auto durationRecursive = chrono::duration_cast<chrono::microseconds>(endRecursive - startRecursive).count();

        // Measure time for iterative Fibonacci calculation
        auto startIterative = chrono::high_resolution_clock::now();
        int iterativeFib = fibIterative(fibIndex);
        auto endIterative = chrono::high_resolution_clock::now();
        auto durationIterative = chrono::duration_cast<chrono::microseconds>(endIterative - startIterative).count();

        // Print Fibonacci numbers and execution times
        cout << "Fibonacci(" << fibIndex << "): Recursive = " << recursiveFib << " | Time: " << durationRecursive << " microseconds, Iterative = " << iterativeFib << " | Time: " << durationIterative << " microseconds" << endl;
    }

    return 0;
}
