#ifndef DATE_H
#define DATE_H
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
};
ostream& operator<<(ostream& os, const Date& d);
#endif
