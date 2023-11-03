/**
 * @file StaticStack.cpp
 * @brief This file contains the implementation of the Stack class and its associated methods.
 */

#include <iostream>

using namespace std;

template <typename TempType>

/**
 * @class Stack
 * @brief Represents a stack data structure.
 */
class Stack
{
private:
    TempType *arr; /**< Pointer to an array for storing elements. */
    int nextIndex; /**< Index for the next element. */
    int capacity; /**< Maximum capacity of the stack. */
    
public:
    /**
     * @brief Default constructor.
     * 
     * Constructs a stack with a default capacity of 10.
     */
    Stack() {
        arr = new TempType[10];
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
        arr = new TempType[capacity];
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
    void push(TempType element) {
        if(nextIndex == capacity) {
            int newCapacity = 2 * capacity;
            TempType* newArr = new TempType[newCapacity];
            
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
    TempType top(void) {
        if(isEmpty()) {
            cout << "Stack is Empty" << endl;
            return 0;
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
    /**< Testing with int */ 
    Stack<int> intStack;
    for(int i = 0; i < 5; i++) {
        intStack.push(i * 10);
    }

    cout << "Int Stack Size: " << intStack.size() << endl;
    cout << "Top element of Int Stack: " << intStack.top() << endl;

    /**< Testing with double */ 
    Stack<double> doubleStack;
    for(double i = 0.5; i < 2.5; i += 0.5) {
        doubleStack.push(i * 10);
    }

    cout << "Double Stack Size: " << doubleStack.size() << endl;
    cout << "Top element of Double Stack: " << doubleStack.top() << endl;

    return 0;
}
