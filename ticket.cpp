#include "ticket.h"
#include "address.h"
using namespace std;
Ticket::Ticket(){
	issueDate=Date();
	location=Address();
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
ostream& operator<<(ostream& os, const Ticket& t) {
    os<< "Issue Date: " <<t.getIssueDate() << endl;
    os<< "Location: " <<t.getLocation();
    return os;
}
