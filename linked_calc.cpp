/*This project is about creating a basic arithmetic calculator using a linked list in C++. Each character of an arithmetic 
expression (like digits, operators, and decimal points) is stored as a node in the linked list. The `LinkedCalc` class handles 
this list, providing methods to add characters, check if the expression is valid, and compute the result. The `validateExpression` 
method ensures the expression follows proper syntax rules, while `evaluateExpression` traverses the list to calculate the final 
result, respecting the order of operations. This approach allows for dynamic, character-by-character parsing and evaluation of 
arithmetic expressions using a linked list structure.*/

#include "linked_calc.hpp"
#include <cctype>
#include <stdexcept>


// Constructor: Here we Initialize the linked list with no elements
template <typename T>
LinkedCalc<T>::LinkedCalc() : head(nullptr) {}

// Destructor: Here we Clean up the linked list and free any allocated memory
template <typename T>
LinkedCalc<T>::~LinkedCalc() {
    clear();
}

// This is the function to clear the linked list and deallocate memory
template <typename T>
void LinkedCalc<T>::clear() {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* next = current->next; // Here we store the next node
        delete current; // Here we delete the current node
        current = next; // Here we move to the next node
    }
    head = nullptr; // Here we set head to nullptr
}

// Here we insert a new value at the end of the linked list
template <typename T>
void LinkedCalc<T>::insert(const T& value) {
    Node<T>* newNode = new Node<T>(value); // Here we create a new node
    if (head == nullptr) {
        head = newNode; // Here if the list is empty, the new node is now the head
    } else {
        Node<T>* current = head;
        while (current->next != nullptr) {
            current = current->next; // Here we traverse to the end of the list
        }
        current->next = newNode; // Here we link the new node at the end
    }
}

// Here we check if a character is a digit (0-9)
template <typename T>
bool LinkedCalc<T>::isDigit(const T& c) {
    return (c >= '0' && c <= '9');
}

// Here we validate if the expression in the linked list is valid
template <typename T>
bool LinkedCalc<T>::validateExpression() {
    if (!head) return false; // Here if the list is empty, the expression is invalid

    Node<T>* current = head;
    bool lastc_digit = false; // Here we track if the last character was a digit
    bool lastc_operator = false; // Here we track if the last character was an operator
    bool lastc_decimal = false; // Here we track if the last character was a decimal point

    while (current != nullptr) {
        if (isDigit(current->data)) {
            lastc_digit = true; // Here if it's a digit, update the tracker
            lastc_operator = false;
            lastc_decimal = false;
        } else if (current->data == '.') {
            if (lastc_decimal || !lastc_digit) return false; // Here we check for consecutive decimals or decimal not after a digit
            lastc_decimal = true;
            lastc_digit = false;
            lastc_operator = false;
        } else if (current->data == '+' || current->data == '-' || current->data == '*' || current->data == '/') {
            if (lastc_operator || !lastc_digit) return false; // Here we check for consecutive operators or operator not after a digit
            lastc_operator = true;
            lastc_digit = false;
            lastc_decimal = false;
        } else {
            return false; // Here we return false if invalid character found
        }
        current = current->next; // Here we move to next node
    }
    return !lastc_operator; // Here we ensure the last character is not an operator
}

// Here we convert a sequence of digit nodes to a float
template <typename T>
float LinkedCalc<T>::convertToFloat(Node<T>*& current) {
    float num = 0.0;
    float deci_plac = 1.0;
    bool isdecim = false;

    while (current != nullptr && (isDigit(current->data) || current->data == '.')) {
        if (current->data == '.') {
            isdecim = true; // Here we start handling decimal places
        } else {
            if (isdecim) {
                deci_plac /= 10.0f;
                num += (current->data - '0') * deci_plac; // Here we add digit as a decimal place
            } else {
                num = num * 10.0f + (current->data - '0'); // Here we add digit as an integer place
            }
        }
        current = current->next; // Here we move to next node
    }
    return num; // Here we return the converted float
}

// Here we evaluate the expression represented by the linked list
template <typename T>
float LinkedCalc<T>::evaluateExpression() {
    if (!validateExpression()) throw std::invalid_argument("Invalid Expression"); // Here we check if the expression is valid

    Node<T>* current = head;
    float answer = 0.0;
    float curr_num = 0.0;
    char curr_op = '+'; // Here we start with a '+' operation to handle the first number

    while (current != nullptr) {
        if (isDigit(current->data) || current->data == '.') {
            curr_num = convertToFloat(current); // Here we convert sequence of digits and decimal points to a float
            continue; // Here we skip to next iteration
        } else if (current->data == '+' || current->data == '-' || current->data == '*' || current->data == '/') {
            // Here we perform last pending operation
            if (curr_op == '+') {
                answer += curr_num;
            } else if (curr_op == '-') {
                answer -= curr_num;
            } else if (curr_op == '*') {
                answer *= curr_num;
            } else if (curr_op == '/') {
                answer /= curr_num;
            }
            curr_op = current->data; // Here we update current operation
            current = current->next; // Here we move to next node
        }
    }

    // Here we perform last pending operation
    if (curr_op == '+') {
        answer += curr_num;
    } else if (curr_op == '-') {
        answer -= curr_num;
    } else if (curr_op == '*') {
        answer *= curr_num;
    } else if (curr_op == '/') {
        answer /= curr_num;
    }

    return answer; // Here we return final answer
}

// Here we are doing explicit template instantiation for the char type
template class LinkedCalc<char>;
