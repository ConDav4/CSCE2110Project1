#ifndef TICKET_H
#define TICKET_H
#include "date.h"
#include <string>
using namespace std;

class Ticket {
    private:
        Date issueDate;
        string location;
    public:
        Ticket();
        Ticket(Date d, string loc);
        void setIssueDate(Date d);
        Date getIssueDate() const;
        void setLocation(string loc);
        string getLocation() const;
};

#endif