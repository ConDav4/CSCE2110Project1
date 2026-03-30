#include "driver.h"
#include <iostream>
using namespace std;

extern Date Today;

Driver::Driver() {
    driverID = "NULL";
	name = "NULL";
	experienceYears = Date(-1,-1,-1);
	dob= Date(-1,-1,-1);
	address  = Address();
	licenseIssueDate = Date();
	ticket = Ticket();
	hasTicket = false;
}


void Driver::setDriverID(string d) {
    driverID = d;
}

string Driver::getDriverID() const {
    return driverID;
}

void Driver::setName(string n) {
    name = n;
}

string Driver::getName() const {
    return name;
}

void Driver::setYearsExperience(Date e) {
    experienceYears = e;
}

Date Driver::getYearsExperience() const {
	return Date::getAge(Today, licenseIssueDate);
}

void Driver::setDOB(Date d) {
    dob = d;
}

Date Driver::getDOB() const {
    return dob;
}

void Driver::setAddress(Address a) {
    address = a;
}

Address Driver::getAddress() const {
    return address;
}

void Driver::setLicenseIssueDate(Date d) {
    licenseIssueDate = d;        
}

Date Driver::getLicenseIssueDate() const {
    return licenseIssueDate;
}

void Driver::setTicket(Ticket t) {
    ticket = t;
}

Ticket Driver::getTicket() const {
    return ticket;
}

void Driver::setTicketStatus(bool t) {
    hasTicket = t;
}

bool Driver::getTicketStatus() const {
    return hasTicket;
}

void Driver::displayDriver() const {
	cout<<"Driver ID = "<<getDriverID()<<endl;
	cout<<"Name = "<<getName()<<endl;
	cout<<"experienceYears = "<<getYearsExperience()<<endl;
	cout<<"Date of Birth = "<<dob<<endl;
	cout<<"Address = "<<getAddress()<<endl;;
	if(getTicketStatus()){
		cout<<"Driver has previous ticket, here is last ticket:"<<endl;
		cout<<ticket <<endl;
	}else{
		cout<<"Driver has no tickets."<<endl;
	}
	cout << endl;
}
#include "driver.h"
#include <iostream>
using namespace std;

extern Date Today;

Driver::Driver() {
    driverID = "NULL";
	name = "NULL";
	experienceYears = Date(-1,-1,-1);
	dob= Date(-1,-1,-1);
	address  = Address();
	licenseIssueDate = Date();
	ticket = Ticket();
	hasTicket = false;
}


void Driver::setDriverID(string d) {
    driverID = d;
}

string Driver::getDriverID() const {
    return driverID;
}

void Driver::setName(string n) {
    name = n;
}

string Driver::getName() const {
    return name;
}

void Driver::setYearsExperience(Date e) {
    experienceYears = e;
}

Date Driver::getYearsExperience() const {
	return Date::getAge(Today, licenseIssueDate);
}

void Driver::setDOB(Date d) {
    dob = d;
}

Date Driver::getDOB() const {
    return dob;
}

void Driver::setAddress(Address a) {
    address = a;
}

Address Driver::getAddress() const {
    return address;
}

void Driver::setLicenseIssueDate(Date d) {
    licenseIssueDate = d;        
}

Date Driver::getLicenseIssueDate() const {
    return licenseIssueDate;
}

void Driver::setTicket(Ticket t) {
    ticket = t;
}

Ticket Driver::getTicket() const {
    return ticket;
}

void Driver::setTicketStatus(bool t) {
    hasTicket = t;
}

bool Driver::getTicketStatus() const {
    return hasTicket;
}

void Driver::displayDriver() const {
	cout<<"Driver ID = "<<getDriverID()<<endl;
	cout<<"Name = "<<getName()<<endl;
	cout<<"experienceYears = "<<getYearsExperience()<<endl;
	cout<<"Date of Birth = "<<dob<<endl;
	cout<<"Address = "<<getAddress();
	if(getTicketStatus()){
		cout<<"Driver has previous ticket, here is last ticket:"<<endl;
		cout<<ticket <<endl;
	}else{
		cout<<"Driver has no tickets."<<endl;
	}
}
