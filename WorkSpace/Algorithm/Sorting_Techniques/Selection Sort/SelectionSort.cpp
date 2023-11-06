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

    unsigned short a = 0xFFFF;
    a = ~( a ^ ( a<<4 ) );

    cout << a;
    return 0;
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
        swap(arr[i], arr[smallestIndex]);
    }
}

