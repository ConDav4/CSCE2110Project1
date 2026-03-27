#include "driver.h"
#include <iostream>
using namespace std;

Driver::Driver() {
    driverID = "NULL";
	name = "NULL";
	experienceYears = -1;
	dob= dob(-1,-1,-1);
	address = NULL;
	licesnseIssueData = NULL;
	ticket = NULL;
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

void Driver::setYearsExperience(int e) {
    experienceYears = e;
}

Date Driver::getYearsExperience() const {
	//Fixme: Add support for Years
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

Date Driver::getAge(Date dob, Date today) {
    //FIXME: Add age calculation
}

void Driver::displayDriver() const {
    //FIXME: Add driver print statements
}
