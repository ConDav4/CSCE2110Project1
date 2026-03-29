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
        int hashFunction(int key) const;
    public:
        HashTable(int size);
        void insert(Driver* d);
        Driver* search(int key) const;
        void remove(int key);
};

#endif
