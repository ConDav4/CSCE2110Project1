#include "ticket.h"
#include "address.h"
using namespace std;

Ticket::Ticket() {
    location = "NULL";
}

Ticket::Ticket(Date d, Address loc) {
    issueDate = d;
    location = loc;
}

void Ticket::setIssueDate(Date d) {
    issueDate = d;
}

Date Ticket::getIssueDate() const {
    return issueDate;
}

void Ticket::setLocation(Address loc) {
    location = loc;
}

Address Ticket::getLocation() const {
    return location;
}
