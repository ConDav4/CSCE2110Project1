#ifndef TICKET_H
#define TICKET_H
#include "date.h"
#include "address.h"
#include <string>
using namespace std;

class Ticket {
    private:
        Date issueDate;
        Address location;
    public:
        Ticket();
        Ticket(Date d, Address loc);
        void setIssueDate(Date d);
        Date getIssueDate() const;
        void setLocation(Address loc);
        string getLocation() const;
};

#endif
