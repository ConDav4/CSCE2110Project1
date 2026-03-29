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
		void printRecentN(int n) const;
		void printOldestN(int n) const;
        Driver* searchDriver(int driverID);
		Node* getHead() const;
		int getSize() const;
        void printAll() const;
};

#endif
