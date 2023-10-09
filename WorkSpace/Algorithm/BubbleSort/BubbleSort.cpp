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
    for(int count = 1; count <= n-1; count++) {
        for(int j = 0; j <= n-2; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
