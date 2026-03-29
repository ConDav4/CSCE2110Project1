#include "databasesystem.h"
using namespace std;

void DatabaseSystem::addDriver(Driver* d) {
    //FIXME: Implement add driver function
    string county = d->getAddress().getCounty();
    activeDrivers.insertByCounty(d, county);
    indexTable.insert(d);
}

void DatabaseSystem::migrateDriver(int id) {
    //FIXME: Implement migrate function
    Driver* d = indexTable.search(id);
    if (d == nullptr) {
        cout << "Driver ID " << id << " not found." << endl;
        return;
    }
	activeDrivers.deleteDriver(id);
	inactiveDrivers.insertAtTail(d);
	indexTable.remove(id);
	cout<<"Driver ID: "<<id<<" has migrated to inactive."<<endl;
}

Driver* DatabaseSystem::searchDriver(int id) const {
    //FIXME: Implement search function
    Driver* d = indexTable.search(id);
    if (d == nullptr){
        cout << "Driver ID " << id << " not found." << endl;
    }
    return d;

}

void DatabaseSystem::getRecentLicenses(int n) const{
	activeDrivers.printRecentN(n);
}
void DatabaseSystem::getOldestLicenses(int n) const{
	activeDrivers.printOldestN(n);
}

void DatabaseSystem::displayAllActive() const {
    cout << "~~~ Active Drivers ~~~" << endl;
    activeDrivers.printAll();
}

void DatabaseSystem::displayAllInactive() const {
    cout << "~~~ Inactive Drivers ~~~" << endl;
    inactiveDrivers.printAll();
}
