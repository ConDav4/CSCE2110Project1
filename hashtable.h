#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "node.h"
#include "driver.h"
using namespace std;

class HashTable {
    private:
        Node *table; //or MiniVector?
        int size;
        int hashFunction(int key);
    public:
        HashTable(int size);
        void insert(int key, Driver* d);
        Driver* search(int key);
        void remove(int key);
};

#endif