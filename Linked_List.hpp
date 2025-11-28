//
//  Linked_List.hpp
//  Data Structures
//
//  Created by Omar Nouh on 11/2/25.
//

#ifndef Linked_List_hpp
#define Linked_List_hpp

#include <stdio.h>
#include <iostream>

using namespace std;
typedef int ElementType;

class LinkedList {
private:
    class Node {
    public:
        ElementType data;
        Node* next;
        Node() : next(0) {}
        Node(ElementType dataValue) : data(dataValue), next(0) {}
    };

    typedef Node* NodePointer;
    NodePointer first;
    int mySize;

public:
    LinkedList();
    LinkedList(const LinkedList& origList);
    ~LinkedList();
    const LinkedList& operator=(const LinkedList& rightSide);
    bool empty();
    void insert(ElementType dataVal, int index);
    void erase(int index);
    int search(ElementType dataVal);
    void display(ostream& out) const;
    int nodeCount();
    void reverse();
    bool ascendingOrder();
    friend istream& operator>>(istream& in, LinkedList& aList);
    // Checks if two lists are equal w.r.t. their contents
    bool equals(LinkedList const& rhs) const;

};

ostream& operator<<(ostream& out, const LinkedList& aList);
istream& operator>>(istream& in, LinkedList& aList);


#endif /* Linked_List_hpp */
