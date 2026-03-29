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
        Driver* searchDriver(int id) const;
        void getRecentLicenses(int n) const;
        void getOldestLicenses(int n) const;
};

#endif
