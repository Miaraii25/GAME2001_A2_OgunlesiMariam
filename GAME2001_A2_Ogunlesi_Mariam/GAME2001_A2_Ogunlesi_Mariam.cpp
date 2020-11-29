#include <iostream>
#include "DoubleLinkedList.h"

using namespace std;

void printDLL(DoubleLinkedList<int> list);

int main() {
    // Create empty DLL
    cout << "--------------------------------------------------------" << endl;
    cout << "Empty list:" << endl;
    cout << "--------------------------------------------------------" << endl;
    DoubleLinkedList<int> dll = DoubleLinkedList<int>();
    printDLL(dll);
    cout << endl;

    // Add value to it
    cout << "--------------------------------------------------------" << endl;
    cout << "List with one element:" << endl;
    cout << "--------------------------------------------------------" << endl;
    node<int>* node1 = new node<int>();
    node1->priority = 1;
    node1->value = 12;
    dll.Push(node1);
    printDLL(dll);
    cout << endl;

    cout << "--------------------------------------------------------" << endl;
    cout << "List with two elements:" << endl;
    cout << "--------------------------------------------------------" << endl;
    node<int>* node2 = new node<int>();
    node2->priority = 3;
    node2->value = 23;
    dll.Push(node2);
    printDLL(dll);
    cout << endl;

    cout << "--------------------------------------------------------" << endl;
    cout << "List with three elements:" << endl;
    cout << "--------------------------------------------------------" << endl;
    node<int>* node3 = new node<int>();
    node3->priority = 2;
    node3->value = 3;
    dll.Push(node3);
    printDLL(dll);
    cout << endl;

    cout << "--------------------------------------------------------" << endl;
    cout << "List with five elements:" << endl;
    cout << "--------------------------------------------------------" << endl;
    node<int>* node4 = new node<int>();
    node4->priority = 1;
    node4->value = 123;
    dll.Push(node4);
    node<int>* node5 = new node<int>();
    node5->priority = 5;
    node5->value = 13;
    dll.Push(node5);
    printDLL(dll);
    cout << endl;

    cout << "--------------------------------------------------------" << endl;
    cout << "Remove first element:" << endl;
    cout << "--------------------------------------------------------" << endl;
    dll.Pop();
    printDLL(dll);
    cout << endl;
    return 0;
}

void printDLL(DoubleLinkedList<int> list) {
    cout << "Data in double-linked list:" << endl;
    node<int>* node = list.Pop();
    if (node != nullptr) {
        cout << "First element is: priority = " << node->priority << " and value = " << node->value << endl;

        node = list.Pop();
        while (node != nullptr) {
            cout << "Next element is: priority = " << node->priority << " and value = " << node->value << endl;
            node = list.Pop();
        }
    }
    else {
        cout << "Empty DLL" << endl;
    }
}
