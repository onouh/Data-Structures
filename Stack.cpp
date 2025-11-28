//
//  Stack.cpp
//  Data Structures
//
//  Created by Omar Nouh on 11/2/25.
//

#include "Stack.hpp"
#include <iostream>

using namespace std;

Stack:: Stack() : myTop(0) {}

Stack:: Stack(const Stack& original) {
    if (original.empty()) {
        myTop = NULL;
    }
    else {
        NodePointer current = original.myTop, /*next = original.myTop->next,*/ myindex = myTop = new Stack::Node(original.top());
        while (current) {
            myindex -> next = new Stack::Node(current->next->data);
            current = current -> next;
        }
    }
}

Stack:: ~Stack() {
    if (empty()) {
        myTop = NULL;
    }
    else {
        NodePointer current = myTop/*, next = myTop -> next*/;
        while (current) {
            NodePointer temp = current;
            current = current -> next;
            delete temp;
        }
    }
}

const Stack& Stack:: operator= (const Stack& rhs) {
    if (this == &rhs) {
        return *this;
    }
    else if (rhs.empty()) {
        this->myTop = NULL;
        return *this;
    }
    else {
        this->~Stack();
        StackPointer stack = new Stack(rhs);
        return *stack;
    }
//    return *this;
}

bool Stack:: empty() const {
    return !myTop;
}

void Stack:: push(const StackElement& value) {
    myTop = new Stack:: Node(value, myTop);
}

void Stack:: pop() {
    NodePointer temp = myTop;
    myTop = myTop -> next;
    delete temp;
}

StackElement Stack:: top() const {
    return myTop -> data;
}

void Stack:: display(ostream& out) const {
    NodePointer current = myTop;
    while (current) {
        out << current -> data << " ";
        current = current -> next;
    }
}

ostream& operator<< (ostream& out, const Stack& aStack) {
    aStack.display(out);
    return out;
}
