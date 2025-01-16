/*This project is about creating a basic arithmetic calculator using a linked list in C++. Each character of an arithmetic 
expression (like digits, operators, and decimal points) is stored as a node in the linked list. The `LinkedCalc` class handles 
this list, providing methods to add characters, check if the expression is valid, and compute the result. The `validateExpression` 
method ensures the expression follows proper syntax rules, while `evaluateExpression` traverses the list to calculate the final 
result, respecting the order of operations. This approach allows for dynamic, character-by-character parsing and evaluation of 
arithmetic expressions using a linked list structure.*/


#include <iostream>
#include <cassert>
#include "linked_calc.cpp" // Here we include the implementation file


using namespace std;

// This is the function to run a series of tests on the evaluateExpression method
void runEvaluateExpressionTests() {
    // Here we run Test 1: Simple addition
    LinkedCalc<char> calc1;
    calc1.insert('1');
    calc1.insert('+');
    calc1.insert('2');
    assert(calc1.validateExpression()); // Here we ensure the expression is valid
    assert(calc1.evaluateExpression() == 3.0f); // Here we check if the result is correct
    cout << "Test 1 passed" << endl;

    // Here we run Test 2: Simple subtraction
    LinkedCalc<char> calc2;
    calc2.insert('5');
    calc2.insert('-');
    calc2.insert('2');
    assert(calc2.validateExpression()); // Here we ensure the expression is valid
    assert(calc2.evaluateExpression() == 3.0f); // Here we check if the result is correct
    cout << "Test 2 passed" << endl;

    // Here we run Test 3: Simple multiplication
    LinkedCalc<char> calc3;
    calc3.insert('3');
    calc3.insert('*');
    calc3.insert('4');
    assert(calc3.validateExpression()); // Here we ensure the expression is valid
    assert(calc3.evaluateExpression() == 12.0f); // Here we check if the result is correct
    cout << "Test 3 passed" << endl;

    // Here we run Test 4: Simple division
    LinkedCalc<char> calc4;
    calc4.insert('8');
    calc4.insert('/');
    calc4.insert('2');
    assert(calc4.validateExpression()); // Here we ensure the expression is valid
    assert(calc4.evaluateExpression() == 4.0f); // Here we check if the result is correct
    cout << "Test 4 passed" << endl;

    // Here we run Test 5: Simple division with decimal result
    LinkedCalc<char> calc5;
    calc5.insert('5');
    calc5.insert('/');
    calc5.insert('2');
    assert(calc5.validateExpression()); // Here we ensure the expression is valid
    assert(calc5.evaluateExpression() == 2.5f); // Here we check if the result is correct
    cout << "Test 5 passed" << endl;

    // Here we run Test 6: Expression with decimal numbers
    LinkedCalc<char> calc6;
    calc6.insert('1');
    calc6.insert('.');
    calc6.insert('5');
    calc6.insert('+');
    calc6.insert('2');
    calc6.insert('.');
    calc6.insert('5');
    assert(calc6.validateExpression()); // Here we ensure the expression is valid
    assert(calc6.evaluateExpression() == 4.0f); // Here we check if the result is correct
    cout << "Test 6 passed" << endl;

    // Here we run Test 7: Another expression with decimal numbers
    LinkedCalc<char> calc7;
    calc7.insert('1');
    calc7.insert('.');
    calc7.insert('5');
    calc7.insert('+');
    calc7.insert('1');
    calc7.insert('.');
    calc7.insert('5');
    assert(calc7.validateExpression()); // Here we ensure the expression is valid
    assert(calc7.evaluateExpression() == 3.0f); // Here we check if the result is correct
    cout << "Test 7 passed" << endl;

    // Here we run Test 8: Invalid expression (consecutive operators)
    LinkedCalc<char> calc8;
    calc8.insert('3');
    calc8.insert('+');
    calc8.insert('*');
    calc8.insert('2');
    assert(!calc8.validateExpression()); // Here the expression should be invalid
    cout << "Test 8 passed" << endl;

    // Here we run Test 9: Invalid expression (consecutive decimals)
    LinkedCalc<char> calc9;
    calc9.insert('3');
    calc9.insert('.');
    calc9.insert('.');
    calc9.insert('2');
    assert(!calc9.validateExpression()); // Here the expression should be invalid
    cout << "Test 9 passed" << endl;

    // Here we run Test 10: Expression ending with an operator
    LinkedCalc<char> calc10;
    calc10.insert('3');
    calc10.insert('+');
    calc10.insert('5');
    calc10.insert('*');
    assert(!calc10.validateExpression()); // Here the expression should be invalid
    cout << "Test 10 passed" << endl;
}

int main() {
    // Here we run evaluateExpression tests to check various scenarios
    runEvaluateExpressionTests();

    // Here if all assertions pass, print a success message
    cout << "All evaluateExpression tests passed!" << endl;

    return 0;
}
