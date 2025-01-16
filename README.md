# Linked List Calculator

This project implements a basic arithmetic calculator in C++ using a **linked list** to parse and evaluate mathematical expressions. Each character of the expression is stored in a linked list node, which allows dynamic parsing and evaluation while respecting operator precedence.

---

## **Features**
1. **Dynamic Linked List Structure**:
   - Each character in the expression (digits, operators, decimal points) is stored as a node in a linked list.

2. **Expression Validation**:
   - Ensures expressions are valid before evaluation:
     - Proper syntax (e.g., no consecutive operators or invalid characters).
     - Handles decimal numbers correctly.

3. **Evaluation**:
   - Supports basic arithmetic operations:
     - Addition (`+`)
     - Subtraction (`-`)
     - Multiplication (`*`)
     - Division (`/`)
   - Handles decimal numbers and floating-point operations.

4. **Unit Testing**:
   - Includes a comprehensive set of tests to validate expression parsing and evaluation.

---

## **How to Run**

### **Requirements**
- C++ compiler (e.g., `g++`).
- All source and header files in the same directory:
  - `linked_calc.hpp`
  - `linked_calc.cpp`
  - `tester.cpp`

### **Steps**
1. Compile the program:
   ```bash
   g++ tester.cpp -o linked_calc_tester
