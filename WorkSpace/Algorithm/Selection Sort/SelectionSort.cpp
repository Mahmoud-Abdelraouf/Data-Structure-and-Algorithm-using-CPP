/**
 * @file main.cpp
 * @brief Implementation of selection sort algorithm.
 */
#include <iostream>
#include <stdint.h>

using namespace std;

/**
 * @brief Sorts an array using selection sort algorithm.
 * @param arr[] The array to be sorted.
 * @param n The number of elements in the array.
 */
void selectionSort(int arr[], int n);;

/**
 * @brief Main function to demonstrate selection sort.
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

    /**< sort the the data of the array */
    selectionSort(arr, n);

    /**< Print the elements after the sorting */
    cout<<"Elements after the sorting: ";
    for(int iterator: arr) {
        cout << iterator << " ";
    }

    return 0;
}

/**
 * @brief Sorts an array using selection sort algorithm.
 * 
 * This function implements the selection sort algorithm to sort the given array
 * in ascending order.
 * 
 * @param arr[] The array to be sorted.
 * @param n The number of elements in the array.
 */
void selectionSort(int arr[], int n) {
    for(int i = 0; i <= n-2; i++) {
        /**< Find the smallest no. */
        int smallestIndex = i;
        for(int j = i+1; j <= n-1; j++) {
                if(arr[j] < arr[smallestIndex]) {
                    smallestIndex = j;
                }
        }
        /**< Compare the smallest value and the current value */
        if(arr[i] > smallestIndex) {
            swap(arr[i], arr[smallestIndex]);
        }
    }
}
