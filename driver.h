#ifndef DRIVER_H
#define DRIVER_H
#include "date.h"
#include "address.h"
#include "ticket.h"
#include <string>
using namespace std;

class Driver {
    private:
        string driverID, name;
        Date dob, licenseIssueDate, experienceYears;
        Address address;
        Ticket ticket;
        bool hasTicket;
    public:
        Driver();
        void setDriverID(string d);
        string getDriverID() const;
        void setName(string n);
        string getName() const;
        void setYearsExperience(int e);
        int getYearsExperience() const;
        void setDOB(Date d);
        Date getDOB() const;
        void setAddress(Address a);
        Address getAddress() const;
        void setLicenseIssueDate(Date d);
        Date getLicenseIssueDate() const;
        void setTicket(Ticket t);
        Ticket getTicket() const;
        void setTicketStatus(bool t);
        bool getTicketStatus() const;
        Date getAge(Date dob);
        void displayDriver() const;
};

#endif
