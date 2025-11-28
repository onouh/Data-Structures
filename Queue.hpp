#pragma once

#include <iostream>
#include <stdexcept>

using namespace std;

template <typename QueueElement>
class Queue {

public:
    Queue();
    Queue(const Queue& original);
    ~Queue();
    const Queue& operator= (const Queue& rhs);
    bool empty() const;
    void enqueue(const QueueElement& value);
    void dequeue();
    void display(ostream& out) const;
    QueueElement first() const;
    QueueElement last() const;
private:
    class Node {
    public:
        QueueElement data;
        Node* next;
        Node(const QueueElement& value, Node* link = nullptr) : data(value), next(link) {}
    };
    typedef Node* NodePointer;
    NodePointer Head; // pointer to front (head) of queue
    NodePointer Tail; // pointer to rear (tail) of queue
};

// --- Implementations (must be in header for templates) ---

template <typename QueueElement>
Queue<QueueElement>::Queue() : Head(nullptr), Tail(nullptr) {}

template <typename QueueElement>
Queue<QueueElement>:: Queue(const Queue& original) {
    if (original.empty()) {
        this();
        return *this;
    } else {
        this -> ~Queue();
        Queue<QueueElement> copy = new Queue();
        NodePointer current = Head = new Queue<QueueElement>::Node:: Node(original.Head->data), myindex = original.Head->next;
        while (myindex) {
            current -> next = new Queue<QueueElement>::Node:: Node(myindex->data);
            current = current -> next;
            if (!myindex->next) {
                Tail = current;
            }
            myindex = myindex -> next;
        }
        return *this;
    }
}

template <typename QueueElement>
Queue<QueueElement>:: ~Queue() {
    if (empty()) {
        Head = Tail = NULL;
    }
    else {
        NodePointer current = Head;
        while (current) {
            NodePointer temp = current;
            current = current -> next;
            delete temp;
        }
    }
}

template <typename QueueElement>
const Queue<QueueElement>& Queue<QueueElement>:: operator= (const Queue& rhs){
    if (this == rhs) {
        return *this;
    } else if (rhs.empty()) {
        Head = Tail = nullptr;
    } else {
        this.~Queue();
        Queue<QueueElement> queue = new Queue<QueueElement>(rhs);
        return *queue;
    }
}

template <typename QueueElement>
bool Queue<QueueElement>:: empty() const {
    return !(bool)Head;
}

template <typename QueueElement>
void Queue<QueueElement>:: enqueue(const QueueElement& value) {
    Tail -> next = new Queue<QueueElement>::Node:: Node(value);
    Tail = Tail -> next;
}

template <typename QueueElement>
void Queue<QueueElement>:: dequeue() {
    NodePointer temp = Head;
    Head = Head -> next;
    delete temp;
}

template <typename QueueElement>
void Queue<QueueElement>:: display(ostream& out) const {
    NodePointer current = Head;
    while (current) {
        out << current -> data << " " << endl;
        current = current -> next;
    }
}

template <typename QueueElement>
QueueElement Queue<QueueElement>:: first() const {
    return Head -> data;
}

template <typename QueueElement>
QueueElement Queue<QueueElement>:: last() const {
    return Tail -> data;
}

template <typename QueueElement>
ostream& operator<<(ostream& out, const Queue<QueueElement>& aQueue) {
    aQueue.display(out);
    return out;
}

/*template <typename QueueElement>
Queue<QueueElement>::Queue() : Head(nullptr), Tail(nullptr) {}

template <typename QueueElement>
Queue<QueueElement>::~Queue() {
    while (Head) {
        NodePointer tmp = Head;
        Head = Head->next;
        delete tmp;
    }
    Tail = nullptr;
}

template <typename QueueElement>
Queue<QueueElement>::Queue(const Queue& original) : Head(nullptr), Tail(nullptr) {
    // deep copy
    NodePointer src = original.Head;
    NodePointer prev = nullptr;
    while (src) {
        NodePointer node = new Node(src->data);
        if (!Head) {
            Head = node;
        } else {
            prev->next = node;
        }
        prev = node;
        src = src->next;
    }
    Tail = prev;
}

template <typename QueueElement>
const Queue<QueueElement>& Queue<QueueElement>::operator=(const Queue& rhs) {
    if (this == &rhs) return *this;
    // clear existing
    while (Head) {
        NodePointer tmp = Head;
        Head = Head->next;
        delete tmp;
    }
    Tail = nullptr;
    // copy from rhs
    NodePointer src = rhs.Head;
    NodePointer prev = nullptr;
    while (src) {
        NodePointer node = new Node(src->data);
        if (!Head) {
            Head = node;
        } else {
            prev->next = node;
        }
        prev = node;
        src = src->next;
    }
    Tail = prev;
    return *this;
}

template <typename QueueElement>
bool Queue<QueueElement>::empty() const {
    return Head == nullptr;
}

template <typename QueueElement>
void Queue<QueueElement>::push(const QueueElement& value) {
    NodePointer node = new Node(value);
    if (!Tail) { // empty queue
        Head = Tail = node;
    } else {
        Tail->next = node;
        Tail = node;
    }
}

template <typename QueueElement>
QueueElement Queue<QueueElement>::top() const {
    if (!Head) throw std::runtime_error("Queue is empty");
    return Head->data;
}

template <typename QueueElement>
void Queue<QueueElement>::pop() {
    if (!Head) throw std::runtime_error("Queue is empty");
    NodePointer tmp = Head;
    Head = Head->next;
    if (!Head) Tail = nullptr;
    delete tmp;
}

template <typename QueueElement>
void Queue<QueueElement>::display(ostream& out) const {
    NodePointer cur = Head;
    out << "[";
    bool first = true;
    while (cur) {
        if (!first) out << ", ";
        out << cur->data;
        first = false;
        cur = cur->next;
    }
    out << "]";
}

template <typename QueueElement>
ostream& operator<< (ostream& out, const Queue<QueueElement>& aQueue) {
    aQueue.display(out);
    return out;
}
*/
