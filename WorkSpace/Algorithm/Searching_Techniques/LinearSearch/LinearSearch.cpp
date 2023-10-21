#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Performs linear search for a key in a given vector.
 *
 * This function searches for the specified key in the provided vector
 * using linear search algorithm. It returns true if the key is found,
 * false otherwise.
 *
 * @param vec The constant reference to the vector in which to search.
 * @param key The integer value to be searched for.
 * @return True if the key is found; false otherwise.
 */
bool linearSearch(const std::vector<int> &vec, int key);

int main() {

    int n = 0, key = 0;

    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> vec(n,0);

    cout << "Enter the data of the array: ";
    for(auto &iterator:vec) {
        cin >> iterator;
    }

    cout << "Enter the Key you search for: ";
    cin >> key;
    
    linearSearch(vec, key);

    return 0;
}

/**
 * @brief Performs linear search in a vector for a specified key.
 * 
 * This function searches for the given key in the provided vector using
 * the linear search algorithm. It returns a boolean indicating whether
 * the key was found or not and prints the index if found.
 * 
 * @param vec The vector to be searched.
 * @param key The key to search for in the vector.
 * @return True if the key was found; false otherwise.
 * 
 * @note The function prints the index if the key is found. If the key
 * is not found, it prints a message indicating that the key was not found.
 */
bool linearSearch(const vector<int> &vec, int key) {
    bool found = false;  /**< Flag to indicate if the key is found */ 

    for (int i = 0; i < vec.size(); i++) {
        if (vec.at(i) == key) {
            found = true;
            cout << "Key found at index: " << i << endl;
        }
    }

    if (!found) {
        cout << "Key not found." << endl;
    }

    return found;  /**< Return a boolean indicating whether the key was found or not. */ 
}