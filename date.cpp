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

ostream& operator<<(ostream& os, const Date& d) {
    os<<d.month<<"/"<<d.day<<"/"<<d.year;
    return os;
}

Date getAge(const Date& today, const Date& dob) {
    int day = today.getDay() - dob.getDay();
    int month = today.getMonth() - dob.getMonth();
    int year = today.getYear() - dob.getYear();

    if (day < 0) {
        month -= 1;
        int daysInPrevMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
        int prevMonth = today.getMonth() - 2;
        if (prevMonth < 0) prevMonth += 12;
        day += daysInPrevMonth[prevMonth];
    }

    if (month < 0) {
        month += 12;
        year -= 1;
    }

    return Date(day, month, year);
}