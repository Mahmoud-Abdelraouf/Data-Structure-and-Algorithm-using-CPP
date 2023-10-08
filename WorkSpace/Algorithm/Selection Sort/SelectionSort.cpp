#include <iostream>
#include <stdint.h>

using namespace std;

/**< the definition of the function */
void selectionSort(int arr[], int n);;

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

/**< Function implementation */
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
