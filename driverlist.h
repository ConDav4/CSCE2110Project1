#ifndef DRIVERLIST_H
#define DRIVERLIST_H
#include "driver.h"
#include "node.h"
using namespace std;

class DriverList {
    private:
        Node *head, *tail;
        int size;
    public:
        DriverList();
        ~DriverList();
        void insertAtHead(Driver* d);
        void insertAtMiddle(Driver* d);
        void insertAtTail(Driver* d);
        void insertByCounty(Driver* d, string co);
        void deleteDriver(int driverID);
        Driver* searchDriver(int driverID);
        void printAll() const;
};

#endif