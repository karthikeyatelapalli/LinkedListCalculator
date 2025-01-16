/*This project is about creating a basic arithmetic calculator using a linked list in C++. Each character of an arithmetic 
expression (like digits, operators, and decimal points) is stored as a node in the linked list. The `LinkedCalc` class handles 
this list, providing methods to add characters, check if the expression is valid, and compute the result. The `validateExpression` 
method ensures the expression follows proper syntax rules, while `evaluateExpression` traverses the list to calculate the final 
result, respecting the order of operations. This approach allows for dynamic, character-by-character parsing and evaluation of 
arithmetic expressions using a linked list structure.*/

#ifndef LINKED_CALC_HPP
#define LINKED_CALC_HPP


#include <iostream>

// This is the node structure to represent each element in the linked list
template <typename T>
struct Node {
    T data;       // This is where the actual data (a character, in our case) is stored
    Node* next;   // This is a pointer to the next node in the list

    // This is the constructor to initialize a node with the given data, next is set to nullptr by default
    Node(const T& data) : data(data), next(nullptr) {}
};

// This is the LinkedCalc class to handles the linked list operations and evaluates arithmetic expressions
template <typename T>
class LinkedCalc {
public:
    // This is constructor to initialize an empty linked list
    LinkedCalc();

    // This is destructor to clean up the linked list and free any allocated memory
    ~LinkedCalc();

    // Here we Insert a new value at the end of the linked list
    void insert(const T& value);

    // Here we validate if the expression in the linked list is valid
    bool validateExpression();

    // Here we evaluate the arithmetic expression stored in the linked list
    float evaluateExpression();

private:
    Node<T>* head;  // This is the pointer to the first node in the linked list

    // Here we check if a character is a digit (0-9)
    bool isDigit(const T& c);

    // Here we convert a sequence of digit nodes (and possibly a decimal point) to a float
    float convertToFloat(Node<T>*& current);

    // Here we clear the linked list and free any allocated memory
    void clear();
};

#endif // LINKED_CALC_HPP
