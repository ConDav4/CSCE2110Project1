#include "driver.h"
#include <iostream>
using namespace std;

Driver::Driver() {
    //FIXME: Configure constructor
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

int Driver::getYearsExperience() const {
    return experienceYears;
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

Date Driver::getAge(Date dob) {
    //FIXME: Add age calculation
}

void Driver::displayDriver() const {
    //FIXME: Add driver print statements
}