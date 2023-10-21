/**
 * @file mergeSort.cpp
 * @brief Implements the merge sort algorithm using recursion and measures the sorting time for various array sizes.
 */

#include <iostream>
#include <chrono>

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
 * @brief Merges two sorted arrays into a single sorted array.
 * 
 * @param a The original array containing two sorted halves to be merged.
 * @param s The starting index of the first half.
 * @param e The ending index of the second half.
 */
void merge(int *a, int s, int e) {
    int mid = (s + e) / 2;
    int i = s;
    int j = mid + 1;
    int k = 0; /**< Index for the temporary array */

    /**< Dynamically allocate memory for the temporary array based on the size of the subarray. */
    int *temp = new int[e - s + 1];

    /**< Merge elements from the two halves into the temporary array. */
    while (i <= mid && j <= e) {
        if (a[i] < a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }

    /**< Copy remaining elements from the first half, if any. */
    while (i <= mid) {
        temp[k++] = a[i++];
    }

    /**< Copy remaining elements from the second half, if any. */
    while (j <= e) {
        temp[k++] = a[j++];
    }

    /**< Copy elements back from the temporary array to the original array. */
    for (int p = s; p <= e; p++) {
        a[p] = temp[p - s]; /**< Adjust the index for the temporary array. */
    }

    /**< Deallocate the dynamically allocated memory to avoid memory leaks. */
    delete[] temp;
}

/**
 * @brief Sorts an array using the merge sort algorithm.
 * 
 * @param a The array to be sorted.
 * @param s The starting index of the range in the array.
 * @param e The ending index of the range in the array.
 */
void mergeSort(int a[], int s, int e) {
    /**< Base case: If the array has one or zero elements, it is already sorted. */
    if (s >= e) {
        return;
    }

    /**< Divide the array into two halves. */
    int mid = (s + e) / 2;

    /**< Recursively sort the first and second halves. */
    mergeSort(a, s, mid);
    mergeSort(a, mid + 1, e);

    /**< Merge the sorted halves. */
    merge(a, s, e);
}


/**
 * @brief Sorts an array using the selection sort algorithm.
 * 
 * This function implements the selection sort algorithm to sort the given array
 * in ascending order.
 * 
 * @param arr[] The array to be sorted.
 * @param n The number of elements in the array.
 */
void selectionSort(int arr[], int n) {
    for(int i = 0; i <= n-2; i++) {
        /**< Find the smallest number in the remaining unsorted part of the array */
        int smallestIndex = i;
        for(int j = i+1; j <= n-1; j++) {
            /**< If the current element is smaller than the smallest element found so far */
            if(arr[j] < arr[smallestIndex]) {
                /**< Update the index of the smallest element */
                smallestIndex = j;
            }
        }
        /**< Swap the smallest element with the first element in the unsorted part of the array */
        std::swap(arr[i], arr[smallestIndex]);
    }
}

int main(void) {
    /**< Loop through different array sizes from 10 to 1,000,000. */
    for(int n = 10; n <= 10000000; n *= 10) {
        /**< Dynamically allocate an array of size 'n' and initialize it with descending values. */
        int *arrMerge = new int[n];
        int *arrSelection = new int[n];
        for(int i = 0; i < n; i++) {
            arrMerge[i] = n - 1;
            arrSelection[i] = n - 1;
        }

        /**< Get the start time in microseconds for merge sort. */
        long long mergeStartTime = getTimeInMicrosecond();

        /**< Sort the array using merge sort. */
        mergeSort(arrMerge, 0, n - 1);

        /**< Get the end time in microseconds for merge sort. */
        long long mergeEndTime = getTimeInMicrosecond();

        /**< Get the start time in microseconds for selection sort. */
        long long selectionStartTime = getTimeInMicrosecond();

        /**< Sort the array using selection sort. */
        selectionSort(arrSelection, n);

        /**< Get the end time in microseconds for selection sort. */
        long long selectionEndTime = getTimeInMicrosecond();

        /**< Print the sorting time for the current array size for both algorithms. */
        std::cout << "Array Size: " << n << " | Merge Sort Time: " << mergeEndTime - mergeStartTime
                  << " microseconds | Selection Sort Time: " << selectionEndTime - selectionStartTime << " microseconds" << std::endl;

        /**< Deallocate the dynamically allocated arrays. */
        delete[] arrMerge;
        delete[] arrSelection;
    }

    return 0;
}
