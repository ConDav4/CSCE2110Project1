#include "driverlist.h"
using namespace std;

DriverList::DriverList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

DriverList::~DriverList() {
    //FIXME: Implement destructor
}

void DriverList::insertAtHead(Driver* d) {
    //FIXME: Implement insert function
}

void DriverList::insertAtMiddle(Driver* d) {
    //FIXME: Implement insert function
}

void DriverList::insertAtTail(Driver* d) {
    //FIXME: Implement insert function
}

void DriverList::insertByCounty(Driver* d, string co) {
    //FIXME: Implement insert function
}

void DriverList::deleteDriver(int driverID) {
    //FIXME: Implement delete function
}

Driver* DriverList::searchDriver(int driverID) {
    //FIXME: Implement search function
}

void DriverList::printAll() const {
    //FIXME: Implement print function
}