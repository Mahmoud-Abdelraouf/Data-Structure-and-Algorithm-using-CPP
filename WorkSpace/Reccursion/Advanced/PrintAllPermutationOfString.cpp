/**
 * @file printPermutation.cpp
 * @brief Prints all permutations of a C-style string using recursion.
 */

#include <iostream>

using namespace std;

/**
 * @brief Prints all permutations of a C-style string using recursion.
 * 
 * This function generates and prints all permutations of the given input C-style string.
 * 
 * @param str The original C-style string for which permutations are generated.
 * @param i The current index being considered for permutation.
 */
void printPermutation(char str[], int i = 0) {
    /**< Base case: end of string */
    if(str[i] == '\0') {
       cout << str << endl;
    }

    /**< Recursive case */
    for(int j = i; str[j] != '\0'; j++) {
        swap(str[i], str[j]); /**< Swap characters to generate permutations. */
        printPermutation(str, i + 1); /**< Recursively generate permutations for the smaller string. */
        swap(str[i], str[j]); /**< Undo the swap for backtracking. */
    }
}

/**
 * @brief Main function to demonstrate printing all permutations of a C-style string using recursion.
 * @return 0 on successful execution.
 */
int main(void) {
    char input[] = "abc"; /**< Example C-style string for which permutations are generated. */
    
    std::cout << "All permutations of \"" << input << "\":" << std::endl;
    printPermutation(input); /**< Generate and print all permutations. */

    return 0;
}
