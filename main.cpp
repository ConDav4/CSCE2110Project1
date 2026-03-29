#include <iostream>
#include <fstream>
#include <sstream>
#include "driver.h"
#include "address.h"
#include "date.h"
using namespace std;
time_t = time(nullptr);
tm* now = localtime(&t);
int Tyear = now->tm_year + 1900;
int Tmonth = now->tm_mon + 1;
int Tday = now->tm_mday;
Date Today(Tday, Tmonth, Tyear) const;

void import(const string& imported, DatabaseSystem& db){
	ifstream file(imported);
	if(!file){
		cout<<"Error: could not open file: " <<imported<<endl;
		return;
	}
	while(getline(file, line)){
		stringstream ss(line);
		string id, name, street, city, county, state, zip, dobDay, dobMonth, dobYear, licDay, licMonth, licYear;
		getline(ss, id, ',');
		getline(ss, name, ',');
		getline(ss, street, ',');
		getline(ss, city, ',');
		getline(ss, county, ',');
		getline(ss, state, ',');
		getline(ss, zip, ',');
		getline(ss, dobDay, ',');
		getline(ss, dobMonth, ',');
		getline(ss, dobYear, ',');
		getline(ss, licDay, ',');
		getline(ss, licMonth, ',');
		getline(ss, licYear, ',');
		Address addr(street, city, county, state, stoi(zip));
		Date dob(stoi(dobDay), stoi(dobMonth), stoi(dobYear));
		Date lic(stoi(licDay), stoi(licMonth), stoi(licYear));
		Driver* d = new Driver();
		d->setDriverID(id);
		d->setDriverName(name);
		d->setAddress(addr);
		d->setDOB(dob);
		d->setYearsExperience(d.getAge(Today, lic));
		d->setLicenseIssueDate(lic);
		db.addDriver(d);
	}
	file.close();
}
int main() {
	int numInput;
	string wordInput;
	bool running = true;

	do {
		//menu loop
	} while (running);
	
	return 0;
}
