/**
 * @file main.cpp
 * @brief Implementation of bubble sort algorithm.
 */

#include <iostream>
#include <stdint.h>

using namespace std;

/**
 * @brief Sorts an array using bubble sort algorithm.
 * @param arr[] The array to be sorted.
 * @param n The number of elements in the array.
 */
void bubbleSort(int arr[], int n);

/**
 * @brief Main function to demonstrate bubble sort.
 * @return 0 on successful execution.
 */
int main(void) {
    /**< Get the size of the array */
    int n = 0;
    cout<< "Enter the number of elements: ";
    cin>>n;

    /**< Declare the Array */
    int arr[n];

    /**< Get the value of the array */
    cout<<"Enter elements you want to sort: ";
    for(int &iterator:arr) {
        cin>>iterator;
    }

    /**< sort the data of the array */
    bubbleSort(arr, n);

    /**< Print the elements after the sorting */
    cout<<"Elements after the sorting: ";
    for(int iterator: arr) {
        cout << iterator << " ";
    }

    return 0;
}

/**
 * @brief Sorts an array using bubble sort algorithm.
 * 
 * This function implements the bubble sort algorithm to sort the given array
 * in ascending order.
 * 
 * @param arr[] The array to be sorted.
 * @param n The number of elements in the array.
 */
void bubbleSort(int arr[], int n) {
    /**< Loop through the array */
    for(int count = 1; count <= n-1; count++) {
        /**< Flag to track if any swaps are made */
        bool flag = false;
        
        /**< Iterate through the array and perform swaps */
        for(int j = 0; j <= n-2; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                flag = true;
            }
        }
        
        /**< If the array is already sorted, exit the loop */
        if(flag == false) {
            /**< The Array is already sorted */
            break;
        }
    }
}
