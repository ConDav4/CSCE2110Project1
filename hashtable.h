#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "node.h"
#include "driver.h"
#include "driverlist.h"
using namespace std;

class HashTable {
    private:
        Node** table;
        int capacity;
        int hashFunction(int key);
    public:
        HashTable(int size);
        void insert(Driver* d);
        Driver* search(int key);
        void remove(int key);
};

#endif