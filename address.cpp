#include "address.h"
using namespace std;
Address::Address() {
    street = "NULL";
    city = "NULL";
    county = "NULL";
    state = "NULL";
    zip = -1;
}

Address::Address(string str, string ci, string co, string sta, int z) {
    street = str;
    city = ci;
    county = co;
    state = sta;
    zip = z;
}

void Address::setStreet(string str) {
    street = str;
}

string Address::getStreet() const {
    return street;
}

void Address::setCity(string ci) {
    city = ci;
}

string Address::getCity() const {
    return city;
}

void Address::setCounty(string co) {
    county = co;
}

string Address::getCounty() const {
    return county;
}

void Address::setState(string sta) {
    state = sta;
}

string Address::getState() const {
    return state;
}

void Address::setZIP(int z) {
    zip = z;
}

int Address::getZIP() const {
    return zip;
}
ostream& operator<<(ostream& os, const Address& a) {
	os << a.getStreet() << endl;
	os << a.getCity() << " " << a.getCounty() << ", " << a.getState() << " " << a.getZIP();
	return os;
}
