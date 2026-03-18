#include "ticket.h"
using namespace std;

Ticket::Ticket() {
    location = "";
}

Ticket::Ticket(Date d, string loc) {
    issueDate = d;
    location = loc;
}

void Ticket::setIssueDate(Date d) {
    issueDate = d;
}

Date Ticket::getIssueDate() const {
    return issueDate;
}

void Ticket::setLocation(string loc) {
    location = loc;
}

string Ticket::getLocation() const {
    return location;
}