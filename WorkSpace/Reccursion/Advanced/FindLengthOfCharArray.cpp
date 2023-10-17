/**
 * @file length.cpp
 * @brief Calculates the length of a C-style string (character array) using recursion.
 */

#include <iostream>

/**
 * @brief Calculates the length of a C-style string using recursion.
 * 
 * This function calculates the length of the given C-style string (character array) using recursion.
 * 
 * @param input The C-style string for which the length is to be calculated.
 * @return The length of the input string.
 */
int length(char input[]) {
    /**< Base case */
    if (input[0] == '\0') {
        return 0; /**< Empty string has length 0. */
    }

    /**< Recursive case */
    int smallLength = length(input + 1); /**< Calculate the length of the smaller string. */

    /**< Calculation */
    return 1 + smallLength; /**< Add 1 for the current character to the length of the smaller string. */
}

/**
 * @brief Converts a C-style string representing an integer to an integer using recursion.
 * 
 * This function converts a C-style string representing an integer to an integer using recursion.
 * 
 * @param str The C-style string to be converted to an integer.
 * @param n The length of the input string.
 * @return The integer equivalent of the input string.
 */
int convertStringToInt(char str[], int n) {
    if(n == 0) {
        return 0; /**< Base case: empty string represents 0. */
    }

    int smallAns = convertStringToInt(str, n-1); /**< Recursively convert the smaller string. */
    int lastDigit = str[n-1] - '0'; /**< Convert the last character to its integer equivalent. */
    int ans = smallAns * 10 + lastDigit; /**< Construct the final integer. */

    return ans;
}

/**
 * @brief Main function to demonstrate calculating the length of a C-style string using recursion.
 * @return 0 on successful execution.
 */
int main(void) {
    char input[] = "Hello, World!"; /**< Example C-style string. */
    char str[]  = "123456"; /**< Another example C-style string representing an integer. */

    int len1 = length(input); /**< Calculate the length of the input string. */
    int len2 = length(str); /**< Calculate the length of the second input string. */

    int convertedInt = convertStringToInt(str, len2); /**< Convert the second string to an integer. */
    
    std::cout << "Length of the string \"" << input << "\" is: " << len1 << std::endl;
    std::cout << "Length of the string \"" << str << "\" is: " << len2 << std::endl;
    std::cout << "Integer value of the string \"" << str << "\": " << convertedInt;

    return 0;
}
