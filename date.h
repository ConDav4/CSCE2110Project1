#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <fstream>
using namespace std;

class Date {
    private:
        int day, month, year;
    public:
        Date();
        Date(int d, int m, int y);
        void setYear(int y);
        int getYear() const;
        void setMonth(int m);
        int getMonth() const;
        void setDay(int d);
        int getDay() const;
        friend ostream& operator<<(ostream& os, const Date& d);
        static Date getAge(const Date& Today, const Date& dob);
};

#endif