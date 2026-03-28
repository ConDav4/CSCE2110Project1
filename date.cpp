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

