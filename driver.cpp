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

Date Date::getAge(Date Today, Date dob){
    int TDay = Today->getDay();
    int TMonth = Today->getMonth();
    int TYear = Today->getYear();
    int dobDay = dob->getDay();
    int dobMonth = dob->getMonth();
    int dobYear = dob->getYear();
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (TDay < dobDay){
        TDay += daysInMonth[dobMonth-1];
        dobMonth--;
    }
    if (dobMonth<TMonth){
        TMonth += 12;
        TYear--;
    }
    int ageDay = TDay - dobDay;
    int ageMonth = TMonth - dobMonth;
    int ageYear = TYear - dobYear;
    Date age(ageDay, ageMonth, ageYear);
    return age;
}

void Driver::displayDriver() const {
	cout<<"Driver ID = "<<driverID<<endl;
	cout<<"Name = "<<name<<endl;
	cout<<"experienceYears = "<<experienceYears<<endl;
	cout<<"Age = "<<getAge(Today, dob)<<endl;
	cout<<"Address = "<<Address;
	if(getTicketStatus()){
		cout<<"Driver has previous ticket, here is last ticket:"<<endl;
		cout<<ticket;
	}else{
		cout<<"Driver has no tickets."<<endl;
	}
}
