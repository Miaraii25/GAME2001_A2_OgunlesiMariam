#include <iostream>

using namespace std;


template<typename T>
struct node {
    int priority;
    T value;
    node* prev = NULL;
    node* next = NULL;
};

template<typename T>
class DoubleLinkedList {
private:
    node<T>* head;
    node<T>* tail;

public:
    DoubleLinkedList<T>();

    ~DoubleLinkedList();

    node<T>* Pop();

    void Push(node<T>* node);

    node<T>* Front();
};

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList() {
    head = NULL;
    tail = NULL;
}

template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList() {

}

template<typename T>
node<T>* DoubleLinkedList<T>::Pop() {
    if (head == NULL) {
        // Check if DLL is empty
        return head;
    }
    else {
        // If not - remove first element and change head and data
        node<T>* data = head;
        if (head->next != NULL) {
            // We have more elements
            head = head->next;
            head->prev = NULL;
        }
        else {
            // We have no more elements
            head = NULL;
            tail = NULL;
        }

        return data;
    }
}

template<typename T>
void DoubleLinkedList<T>::Push(node<T>* data) {
    // Check if head is empty
    if (head == NULL) {
        head = data;
        data->next = NULL;
        data->prev = NULL;
        tail = head;
    }
    else {
        // Find proper place to add new node
        node<T>* current = head;
        node<T>* prev = NULL;

        // Find node to insert after
        while (current != NULL && current->priority <= data->priority) {
            prev = current;
            current = current->next;
        }

        // Insert new node
        prev->next = data;
        data->prev = prev;
        // If we don't add it tail
        if (current != NULL) {
            current->prev = data;
            data->next = current;
        }
        else {
            tail = data;
        }

    }
}

template<typename T>
node<T>* DoubleLinkedList<T>::Front() {
    return head;
}

