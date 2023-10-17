/**
 * @file removeConsecutiveDuplicates.cpp
 * @brief Removes consecutive duplicate characters from a C-style string using recursion.
 */

#include <iostream>

/**
 * @brief Removes consecutive duplicate characters from a C-style string using recursion.
 * 
 * This function removes consecutive duplicate characters from the given C-style string.
 * 
 * @param input The C-style string from which consecutive duplicate characters are to be removed.
 */
void removeConsecutiveDuplicates(char input[]) {
    /**< Base case: empty string */
    if (input[0] == '\0') {
        return; /**< End of string, return without further modification. */
    }

    /**< Check if the current character is the same as the next character */
    if (input[0] != input[1]) {
        removeConsecutiveDuplicates(input + 1); /**< If not, move to the next character. */
    } else {
        /**< If consecutive duplicates found, remove the duplicate character */
        for (int i = 0; input[i] != '\0'; i++) {
            input[i] = input[i + 1]; /**< Shift characters to remove the duplicate. */
        }
        removeConsecutiveDuplicates(input); /**< Recursively remove more consecutive duplicates. */
    }
}

/**
 * @brief Main function to demonstrate removing consecutive duplicate characters in a C-style string using recursion.
 * @return 0 on successful execution.
 */
int main(void) {
    char input[] = "aaabbbcccdddeee"; /**< Example C-style string with consecutive duplicates. */

    std::cout << "Original string: " << input << std::endl;
    removeConsecutiveDuplicates(input); /**< Remove consecutive duplicates from the input string. */
    std::cout << "Modified string: " << input;

    return 0;
}
