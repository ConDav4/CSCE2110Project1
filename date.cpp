#include "date.h"
using namespace std;

Date::Date() {
    day = 0;
    month = 0;
    year = 0;
}

Date::Date(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}

void Date::setYear(int y) {
    year = y;
}

int Date::getYear() const {
    return year;
}

void Date::setMonth(int m) {
    month = m;
}

int Date::getMonth() const {
    return month;
}

void Date::setDay(int d) {
    day = d;
}

int Date::getDay() const {
    return day;
}

ostream& Date::operator<<(ostream& os, const Date& d) {
    os<<d.getMonth()<<"/"<<d.getDay()<<"/"<<d.getYear();
    return os;
}

Date Date::getAge(Date current, Date dob) {
    int TDay = current.getDay();
    int TMonth = current.getMonth();
    int TYear = current.getYear();
    int dobDay = dob.getDay();
    int dobMonth = dob.getMonth();
    int dobYear = dob.getYear();
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (TDay < dobDay){
        TDay += daysInMonth[TMonth - 1];
        TMonth -= 1;
    }
    if (dobMonth > TMonth) {
        TYear -= 1;
        TMonth += 12;
    }
    Date age((TYear - dobYear), (TMonth - dobMonth), (TDay - dobDay));
    return age;
}