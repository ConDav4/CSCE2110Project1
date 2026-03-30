#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>
#include <fstream>
using namespace std;

class Address {
    private:
        string street, city, county, state;
        int zip;
    public:
        Address();
        Address(string str, string ci, string co, string sta, int z);
        void setStreet(string str);
        string getStreet() const;
        void setCity(string ci);
        string getCity() const;
        void setCounty(string co);
        string getCounty() const;
        void setState(string sta);
        string getState() const;
        void setZIP(int z);
        int getZIP() const;
        ostream& operator<<(ostream& os, const Address& a);
};

#endif
