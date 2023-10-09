/**
 * @file main.cpp
 * @brief Implementation of binary search algorithm.
 */

using namespace std;

/**< Mater Headers Files */
#include <bits/stdc++.h>

/**
 * @brief Performs binary search for a key in a sorted array.
 * 
 * This function searches for the specified key in the provided sorted array
 * using binary search algorithm. It returns the index of the key if found,
 * -1 otherwise.
 * 
 * @param arr The sorted array to be searched.
 * @param n The number of elements in the array.
 * @param key The integer value to be searched for.
 * @return Index of the key if found; -1 otherwise.
 */
int binarySearch(int arr[], int n, int key);

/**
 * @brief Main function to demonstrate binary search.
 * @return 0 on successful execution.
 */
int main() {
    int n = 0, key = 0;

    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];

    cout << "Enter the data of the array: ";
    for(auto &iterator : arr) {
        std::cin >> iterator;
    }

    /**< sort the array to can use the Binary search */
    sort(arr, arr+n);

    /**< Print the data after the sorting */
    cout << "-----------------------------------\n  The array after sorting the data\n------------------------------------\n";
    for(auto iterator:arr) {
        cout << iterator << "\t";  
    }
    cout << endl;

    cout << "Enter the Key you search for: ";
    cin >> key;

    int index = binarySearch(arr, n, key);

    if(index != -1) {
        cout << "Key found at index: " << index;
    } else {
        cout << "Key not found.";
    }

    return 0;
}

/**
 * @brief Performs binary search for a key in a sorted array.
 * 
 * This function searches for the specified key in the provided sorted array
 * using binary search algorithm. It returns the index of the key if found,
 * -1 otherwise.
 * 
 * @param arr The sorted array to be searched.
 * @param n The number of elements in the array.
 * @param key The integer value to be searched for.
 * @return Index of the key if found; -1 otherwise.
 */
int binarySearch(int arr[], int n, int key) {

    int s = 0, e = n - 1, mid = 0;
    while(s <= e) {
        mid = (s + ((e - s) / 2));
        if(key == arr[mid]) { 
            return mid; 
        }
        else if(key < arr[mid]) { 
            e = mid - 1; 
        }
        else { 
            s = mid + 1; 
        }
    }

    return -1; /**< Key not found in the array. */
}
