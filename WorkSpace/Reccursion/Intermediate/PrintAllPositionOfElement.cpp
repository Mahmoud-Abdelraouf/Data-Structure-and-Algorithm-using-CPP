/**
 * @file printAllPos.cpp
 * @brief Contains functions to manipulate an array and find positions and occurrences of a specific element using recursion.
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Prints all positions of a specific element in an array using recursion.
 * 
 * This function prints all positions (indices) of the given element in the given array.
 * 
 * @param a The array of integers.
 * @param n The number of elements in the array.
 * @param x The element to search for.
 * @param i The current index being checked.
 */
void printAllPos(int a[], int n, int x, int i) {
    /**< Base case */
    if(i == n) {
        return; /**< End of array, return without printing. */
    }

    /**< Check if the current element matches the target element */
    if(a[i] == x) {
        cout << i << " "; /**< Print the index if the element is found. */
    }

    /**< Recursive case */
    printAllPos(a, n, x, i + 1); /**< Search for the element in the rest of the array. */
}

/**
 * @brief Counts the occurrences of a specific element in an array using recursion.
 * 
 * This function counts the occurrences of the given element in the given array.
 * 
 * @param a The array of integers.
 * @param n The number of elements in the array.
 * @param x The element to count occurrences for.
 * @param i The current index being checked.
 * @return The number of occurrences of the element in the array.
 */
int count(int a[], int n, int x, int i) {
    /**< Base case */
    if(i == n) {
        return 0; /**< End of array, return zero occurrences. */
    }

    /**< Check if the current element matches the target element */
    if(a[i] == x) {
        return 1 + count(a, n, x, i + 1); /**< If found, count this occurrence and search in the rest of the array. */
    }

    /**< Recursive case */
    return count(a, n, x, i + 1); /**< Search for the element in the rest of the array. */
}

/**
 * @brief Stores all positions of a specific element in an array using recursion.
 * 
 * This function stores all positions (indices) of the given element in the given array in a vector.
 * 
 * @param a The array of integers.
 * @param n The number of elements in the array.
 * @param x The element to search for.
 * @param i The current index being checked.
 * @param ans The vector to store the positions.
 */
void storeAllPos(int a[], int n, int x, int i, vector<int>& ans) {
    /**< Base case */
    if(i == n) {
        return; /**< End of array, return without storing. */
    }

    /**< Check if the current element matches the target element */
    if(a[i] == x) {
        ans.push_back(i); /**< If found, store the index in the vector. */
    }

    /**< Recursive case */
    storeAllPos(a, n, x, i + 1, ans); /**< Search for the element in the rest of the array. */
}

/**
 * @brief Main function to demonstrate printing all positions and counting occurrences of an element in an array using recursion.
 * @return 0 on successful execution.
 */
int main(void) {
    int arr[] = {1, 2, 3, 2, 4, 2, 5}; /**< Example array of integers. */
    int n = sizeof(arr) / sizeof(arr[0]); /**< Calculate the number of elements in the array. */
    int x = 2; /**< Element to search for. */

    cout << "Positions of element " << x << " in the array: ";
    printAllPos(arr, n, x, 0); /**< Print all positions of the element. */
    cout << endl;

    int occurrences = count(arr, n, x, 0); /**< Count occurrences of the element. */
    cout << "Number of occurrences of element " << x << " in the array: " << occurrences << endl;

    vector<int> positions;
    storeAllPos(arr, n, x, 0, positions); /**< Store all positions of the element in the vector. */
    cout << "Stored positions of element " << x << " in the array: ";
    for(int pos : positions) {
        cout << pos << " ";
    }
    cout << endl;

    return 0;
}
