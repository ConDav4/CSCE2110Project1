#include "hashtable.h"
#include <iostream>
using namespace std;

HashTable::HashTable(int size) {
    capacity = size;
    table = new Node*[capacity];

    for (int i = 0; i < capacity; i++) {
        table[i] = nullptr;
    }
}

int HashTable::hashFunction(int key) {
    return key % capacity;
}

void HashTable::insert(Driver* d) {
    int index = hashFunction(stoi(d->getDriverID()));

    Node* newNode = new Node(d);

    newNode->next = table[index];
    table[index] = newNode;
}

Driver* HashTable::search(int key) {
    int index = hashFunction(key);

    Node* temp = table[index];

    while (temp != nullptr) {
        if (stoi(temp->data->getDriverID()) == key) {
            return temp->data;
        }
        temp = temp->next;
    }

    return nullptr;
}

void HashTable::remove(int key) {
    int index = hashFunction(key);

    Node* temp = table[index];
    Node* prev = nullptr;

    while (temp != nullptr) {
        if (stoi(temp->data->getDriverID()) == key) {
            if (prev == nullptr) {
                table[index] = temp->next;
            } else {
                prev->next = temp->next;
            }
            delete temp;
            return;
        }
        
        prev = temp;
        temp = temp->next;
    }
}