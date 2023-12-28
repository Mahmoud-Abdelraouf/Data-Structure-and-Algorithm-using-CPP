/**
 * @file LinkedList.cpp
 * @brief This file contains the implementation of the LinkedList class and its associated methods.
 */

#include <iostream>

/**
 * @brief Represents a Node in a linked list.
 */
class Node {
private:
    int data; /**< Data stored in the Node */ 
    Node* next; /**< Pointer to the next Node in the list */ 

public:
    /**
     * @brief Constructor to initialize a Node with given data and null next pointer.
     * @param data The data to be stored in the Node.
     */
    Node(int data) {
        this->data = data;
        next = nullptr;
    }

    /**
     * @brief Getter method to retrieve the data of the Node.
     * @return The data stored in the Node.
     */
    int getData() const {
        return data;
    }

    /**
     * @brief Setter method to set the next pointer of the Node.
     * @param node Pointer to the next Node in the list.
     */
    void setNext(Node* node) {
        this->next = node;
    }

    /**
     * @brief Getter method to retrieve the next pointer of the Node.
     * @return Pointer to the next Node in the list.
     */
    Node* getNext() const {
        return next;
    }
};

/**
 * @brief Represents a singly linked list.
 */
class LinkedList {
private:
    Node* head; /**< Pointer to the first Node in the list */ 

public:
    /**
     * @brief Constructor to initialize an empty linked list.
     */
    LinkedList() {
        head = nullptr;
    }

    /**
     * @brief Destructor to release memory occupied by the nodes when LinkedList object is destroyed.
     */
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->getNext();
            delete temp;
        }
    }

    /**
      * @brief Inserts a new node with the given data at the end of the linked list.
      *
      * This method creates a new node with the provided data and inserts it at the end
      * of the linked list. If the list is empty, the new node becomes both the head and
      * the tail of the list.
      *
      * @param data The data to be inserted into the linked list.
      *
      * @note The LinkedList class owns the memory allocated for the nodes. 
      *       It is responsible for deallocating the memory when the linked list is destroyed.
      */
    void insert(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode; /**< If the list is empty, the new node becomes the head */ 
        } else {
            Node* current = head;
            while (current->getNext() != nullptr) {
                current = current->getNext();
            }
            current->setNext(newNode); /**< Inserting the new node at the end */ 
        }
    }

    /**
     * @brief Method to delete a node with given data from the linked list.
     * @param data The data to be removed from the linked list.
     */
    void remove(int data) {
        if (head == nullptr) {
            return; /**< Nothing to delete in an empty list */ 
        }

        if (head->getData() == data) {
            Node* temp = head;
            head = head->getNext();
            delete temp;
            return;
        }

        Node* current = head;
        while (current->getNext() != nullptr && current->getNext()->getData() != data) {
            current = current->getNext();
        }

        if (current->getNext() != nullptr) {
            Node* temp = current->getNext();
            current->setNext(temp->getNext());
            delete temp;
        }
    }

    /**
      * @brief Checks if the linked list is empty.
      *
      * This function checks if the head pointer is nullptr, indicating that the linked list is empty.
      *
      * @return True if the linked list is empty, otherwise false.
      */
    bool isEmpty(void) const {
        return head == nullptr;
    }

    /**
      * @brief Calculates the length of the linked list.
      *
      * This function iterates through the linked list and counts the number of nodes,
      * effectively determining the length of the list.
      *
      * @return The length of the linked list.
      */
    int getLength(void) const {
        int length = 0; /**< Initialize the length counter to zero. */
        Node *temp = head; /**< Create a temporary pointer to traverse the list, starting from the head. */

        while(temp) {   
            length++; /**< Increment the length for each node encountered. */
            temp = temp->getNext(); /**< Move to the next node. */
        }
        return length; /**< Return the final length of the linked list. */
    }

    /**
      * @brief Inserts a new node with the given data at the front of the linked list.
      *
      * This function creates a new node with the provided data and inserts it at the front
      * of the linked list. If the list is empty, the new node becomes the head of the list.
      *
      * @param data The data to be inserted at the front of the linked list.
      *
      * @note The LinkedList class owns the memory allocated for the nodes.
      *       It is responsible for deallocating the memory when the linked list is destroyed.
      */
    void pushFront(int data) {
        /**< Create a new node with the provided data */ 
        Node *newNode = new Node(data);

        // If the list is empty, set the new node as the head
        if(head == nullptr) {
            head = newNode;
        } else {
            /**< If the list is not empty, update pointers to insert the new node at the front */ 
            newNode->setNext(head); /**< Set the next pointer of the new node to the current head */ 
            head = newNode; /**< Update the head to point to the new node */ 
        }
    }

    /**
      * @brief Removes the first node from the linked list.
      *
      * If the linked list is not empty, this function removes the first node,
      * deallocates the memory associated with it, and updates the head pointer
      * to point to the new first node.
      */
    void popFront() {
        if (head == nullptr) {
            return; /**< Nothing to remove from an empty list */ 
        } else {
            Node *tempDeletedNode = head; /**< Store a reference to the first node */ 
            head = head->getNext(); /**< Update head to point to the next node */ 
            delete tempDeletedNode; /**< Deallocate memory of the removed node */ 
        }
    }


    /**
     * @brief Method to print the elements of the linked list.
     */
    void print() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->getData() << " -> ";
            current = current->getNext();
        }
        std::cout << "nullptr" << std::endl;
    }
};

/**
 * @brief Main function to demonstrate the LinkedList class.
 * @return 0 on successful execution.
 */
int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);

    std::cout << "Original Linked List: ";
    list.print();

    list.remove(2);
    std::cout << "Linked List after removing 2: ";
    list.print();

    return 0;
}
