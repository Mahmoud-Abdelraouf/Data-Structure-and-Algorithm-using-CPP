/**
 * @file StaticStack.cpp
 * @brief This file contains the implementation of the Stack class and its associated methods.
 */

#include <iostream>

using namespace std;

/**
 * @class Stack
 * @brief Represents a stack data structure.
 */
class Stack
{
private:
    int *arr; /**< Pointer to an array for storing elements. */
    int nextIndex; /**< Index for the next element. */
    int capacity; /**< Maximum capacity of the stack. */
    
public:
    /**
     * @brief Default constructor.
     * 
     * Constructs a stack with a default capacity of 10.
     */
    Stack() {
        arr = new int[10];
        nextIndex = 0;
        capacity = 10;
    }

    /**
     * @brief Parameterized constructor.
     * 
     * Constructs a stack with a specified capacity.
     * @param cap The capacity of the stack.
     */
    Stack(int cap) {
        capacity = cap;
        arr = new int[capacity];
        nextIndex = 0;
    }

    /**
     * @brief Get the current size of the stack.
     * @return The size of the stack.
     */
    int size() {
        return nextIndex;
    }

    /**
     * @brief Check if the stack is empty.
     * @return True if the stack is empty, false otherwise.
     */
    bool isEmpty() {
        return nextIndex == 0;
    }

     /**
     * @brief Push an element onto the stack.
     * 
     * If the stack is full, it will double its capacity and copy existing elements.
     * @param element The element to be pushed.
     */
    void push(int element) {
        if(nextIndex == capacity) {
            int newCapacity = 2 * capacity;
            int* newArr = new int[newCapacity];
            
            for(int i = 0; i < capacity; i++) {
                newArr[i] = arr[i];
            }

            delete[] arr; /**< Deallocate old memory */ 
            arr = newArr; /**< Update pointer */
            capacity = newCapacity; /**< Update capacity */ 

            cout << "Capacity doubled to " << newCapacity << endl;
        }
        arr[nextIndex] = element;
        nextIndex++;
    }

    /**
     * @brief Pop an element from the stack.
     * 
     * If the stack is empty, an error message is printed.
     */
    void pop(void) {
        if(isEmpty()) {
            cout << "Stack is Empty" << endl;
            return;
        }
        nextIndex--;
    }

    /**
     * @brief Get the top element of the stack.
     * 
     * If the stack is empty, an error message is printed and -1 is returned.
     * @return The top element of the stack.
     */
    int top(void) {
        if(isEmpty()) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return arr[nextIndex - 1];
    }

    /**
     * @brief Destructor.
     * 
     * Deallocates the memory allocated for the stack.
     */
    ~Stack() {
        delete[] arr; /**< Deallocate the memory allocated in the constructor */  
    }
};

/**
 * @brief Main function to demonstrate the Stack class.
 * @return 0 on successful execution.
 */
int main() 
{
    /**< Create a stack with default capacity (10) */ 
    Stack s1;

    /**< Push elements onto the stack */ 
    for(int i = 0; i < 15; i++) {
        s1.push(i * 10);
    }

    /**< Print the size of the stack */ 
    cout << "Size of s1: " << s1.size() << endl;

    /**<  Print the top element of the stack */   
    cout << "Top element of s1: " << s1.top() << endl;

    return 0;
}