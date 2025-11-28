//
//  Stack.hpp
//  Data Structures
//
//  Created by Omar Nouh on 11/2/25.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>
#include <iostream>
using namespace std;
typedef int StackElement;

class Stack {

public:
    Stack();
    Stack(const Stack& original);
    ~Stack();
    const Stack& operator= (const Stack& rhs);
    bool empty() const;
    void push(const StackElement& value);
    void display(ostream& out) const;
    StackElement top() const;
    void pop();
private:
    class Node {
    public:
        StackElement data;
        Node* next;
        Node(StackElement value, Node* link = 0) : data(value), next(link) {}
    };
    typedef Stack* StackPointer;
    typedef Node* NodePointer;
    NodePointer myTop; // Pointer to top node of stack
};

ostream& operator<< (ostream& out, const Stack& aStack);

#endif /* Stack_hpp */
