#include <iostream>
#include <chrono>
#include <cassert>

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
 * @brief Finds the minimum value in an array within a specified range.
 * 
 * @param x The input array.
 * @param start The starting index of the range.
 * @param end The ending index of the range.
 * @return The minimum value within the specified range.
 */
double min(double x[], int start, int end) {
    assert(end >= start && start >= 0);
    if (end == start)
        return x[start];

    int mid = (start + end) / 2;
    double min1 = min(x, start, mid);
    double min2 = min(x, mid + 1, end);
    
    if (min1 <= min2)
        return min1;
    else
        return min2;
}

int main() {
    const int maxArraySize = 100000; // Define the maximum size of the array

    for (int arraySize = 1000; arraySize <= maxArraySize; arraySize += 1000) {
        double testArray[arraySize]; // Create a test array

        // Initialize the test array with random values (between 0 and 1)
        for (int i = 0; i < arraySize; i++) {
            testArray[i] = ((double)rand() / RAND_MAX);
        }

        // Measure time for min function
        auto start = chrono::high_resolution_clock::now();
        double minValue = min(testArray, 0, arraySize - 1);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();

        // Print the size, result, and execution time
        cout << "Array Size: " << arraySize << " | Minimum value: " << minValue << " | Execution time: " << duration << " microseconds" << endl;
    }

    return 0;
}

