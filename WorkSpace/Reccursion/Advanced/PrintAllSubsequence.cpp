/**
 * @file printSubstrings.cpp
 * @brief Prints all possible substrings of a string using recursion.
 */

#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Prints all possible substrings of a string using recursion.
 * 
 * This function generates and prints all possible substrings of the given input string.
 * 
 * @param input The original string for which substrings are generated.
 * @param output The current substring being generated.
 */
void print_subs(string input, string output) {
    /**< Base case: input string is empty */
    if (input.length() == 0) {
        cout << output << endl; /**< Print the generated substring. */
        return; /**< Return to avoid further recursion. */
    }

    /**< Recursive case */
    print_subs(input.substr(1), output + input[0]); /**< Include the first character in the substring. */
    print_subs(input.substr(1), output); /**< Exclude the first character of input string. */
}

/**
 * @brief Main function to demonstrate printing all possible substrings of a string using recursion.
 * @return 0 on successful execution.
 */
int main(void) {
    string input = "abc"; /**< Example input string. */
    
    cout << "All substrings of \"" << input << "\":" << endl;
    print_subs(input, ""); /**< Generate and print all possible substrings. */

    return 0;
}
