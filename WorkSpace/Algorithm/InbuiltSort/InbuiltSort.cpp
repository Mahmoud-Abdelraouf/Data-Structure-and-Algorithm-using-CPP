/**
 * @file main.cpp
 * @brief Implementation of sorting an array using the sort() function.
 */

/**< Mater Headers Files */
#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Main function to demonstrate sorting using the sort() function.
 * @return 0 on successful execution.
 */
int main(void) {
    /**< Get the size of the array */
    int n = 0;
    cout << "Enter the number of elements: ";
    cin >> n;

    /**< Declare the Array */
    int arr[n];

    /**< Get the value of the array */
    cout << "Enter elements you want to sort: ";
    for (int &iterator : arr) {
        cin >> iterator;
    }

    /**< Sorts the array elements in ascending order using the C++ standard library sort() function. */
    sort(arr, arr + n);

    /**< Print the elements after sorting */
    cout << "Elements after sorting: ";
    for (int iterator : arr) {
        cout << iterator << " ";
    }

    return 0;
}
