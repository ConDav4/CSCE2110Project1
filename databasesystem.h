#ifndef DATABASESYSTEM_H
#define DATABASESYSTEM_H
#include "hashtable.h"
#include "driverlist.h"
#include "driver.h"
using namespace std;

class DatabaseSystem {
    private:
        DriverList activeDrivers, inactiveDrivers;
        HashTable indexTable;
    public:
        void addDriver(Driver* d);
        void migrateDriver(int id);
        Driver* searchDriver(int id);
        void getRecentLicenses(int n);
        void getOldestLicenses(int n);
};

#endif