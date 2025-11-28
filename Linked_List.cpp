    //
    //  Linked_List.cpp
    //  Data Structures
    //
    //  Created by Omar Nouh on 11/2/25.
    //

    #include "Linked_List.hpp"

    LinkedList::LinkedList() : first(0), mySize(0) {}
    LinkedList::~LinkedList() {
        NodePointer current = first;
        NodePointer nextNode;
        while (current != 0) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
        first = 0;
        mySize = 0;
    }
    bool LinkedList::empty() {
        return mySize == 0;
    }
    void LinkedList::display(ostream& out) const {
        NodePointer current = first;
        while (current != 0) {
            out << current->data << "  ";
            current = current->next;
        }
    }
    void LinkedList::insert(ElementType dataVal, int index) {
        if (index < 0 || index > mySize) {
            return; // invalid index
        }
        // simple insertion at head or after
        NodePointer newNode = new Node(dataVal);
        if (index == 0) {
            newNode->next = first;
            first = newNode;
        } else {
            NodePointer prev = first;
            for (int i = 1; i < index; ++i) {
                prev = prev->next;
            }
            newNode->next = prev->next;
            prev->next = newNode;
        }
        ++mySize;
    }
    void LinkedList::erase(int index) {
        if (index < 0 || index >= mySize) {
            return; // invalid index
        }
        NodePointer toDelete;
        if (index == 0) {
            toDelete = first;
            first = first->next;
        } else {
            NodePointer prev = first;
            for (int i = 1; i < index; ++i) {
                prev = prev->next;
            }
            toDelete = prev->next;
            prev->next = toDelete->next;
        }
        delete toDelete;
        --mySize;
    }
    int LinkedList::search(ElementType dataVal) {
        NodePointer current = first;
        int index = 0;
        while (current != 0) {
            if (current->data == dataVal) {
                return index;
            }
            current = current->next;
            ++index;
        }
        return -1; // not found
    }
    int LinkedList::nodeCount() {
        return mySize;
    }
    ostream& operator<<(ostream& out, const LinkedList& aList) {
        aList.display(out);
        return out;
    }
    istream& operator>>(istream& in, LinkedList& aList) {
        ElementType value;
        while (in >> value) {
            aList.insert(value, aList.mySize);
        }
        return in;
    }
    bool LinkedList::equals(LinkedList const& rhs) const {
        if (mySize != rhs.mySize) {
            return false;
        }
        NodePointer current1 = first;
        NodePointer current2 = rhs.first;
        while (current1 != 0) {
            if (current1->data != current2->data) {
                return false;
            }
            current1 = current1->next;
            current2 = current2->next;
        }
        return true;
    }
