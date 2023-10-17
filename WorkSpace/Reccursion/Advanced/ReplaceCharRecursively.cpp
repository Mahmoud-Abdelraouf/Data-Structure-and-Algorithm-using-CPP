/**
 * @file replaceChar.cpp
 * @brief Replaces all occurrences of a character in a C-style string and removes a specific character using recursion.
 */

#include <iostream>

/**
 * @brief Replaces all occurrences of a character in a C-style string using recursion.
 * 
 * This function replaces all occurrences of the character 'x' with the character 'y' in the given C-style string.
 * 
 * @param input The C-style string in which characters are to be replaced.
 * @param x The character to be replaced.
 * @param y The character to replace 'x' with.
 */
void replaceChar(char input[], char x, char y) {
    /**< Base case */
    if (input[0] == '\0') {
        return; /**< End of string, return without further modification. */
    }

    /**< Check if the current character matches the target character */
    if (input[0] == x) {
        input[0] = y; /**< Replace 'x' with 'y'. */
    }

    /**< Recursive case */
    replaceChar(input + 1, x, y); /**< Continue replacing in the rest of the string. */
}

/**
 * @brief Removes all occurrences of a character in a C-style string using recursion.
 * 
 * This function removes all occurrences of the character 'x' from the given C-style string.
 * 
 * @param input The C-style string from which characters are to be removed.
 * @param x The character to be removed.
 */
void removeChar(char input[], char x) {
    /**< Base case */
    if (input[0] == '\0') {
        return; /**< End of string, return without further modification. */
    }

    /**< Check if the current character matches the target character */
    if (input[0] == x) {
        for (int i = 0; input[i] != '\0'; i++) {
            input[i] = input[i + 1]; /**< Remove 'x' from the string. */
        }
        removeChar(input, x); /**< Recursively remove more occurrences. */
    } else {
        removeChar(input + 1, x); /**< Continue removing in the rest of the string. */
    }
}

/**
 * @brief Main function to demonstrate replacing and removing characters in a C-style string using recursion.
 * @return 0 on successful execution.
 */
int main(void) {
    char input[] = "Hello, World!"; /**< Example C-style string. */
    char replaceX = 'o'; /**< Character to be replaced. */
    char replaceY = 'x'; /**< Character to replace 'o' with. */
    char removeX = 'l'; /**< Character to be removed. */

    replaceChar(input, replaceX, replaceY); /**< Replace characters in the input string. */
    removeChar(input, removeX); /**< Remove characters from the modified string. */

    std::cout << "Modified string: " << input;

    return 0;
}
