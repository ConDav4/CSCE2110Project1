#ifndef AGEDRIVER_H
#define AGEDRIVER_H
#include "driver.h"
using namespace std;

class AgeDriver : public Driver {
    protected:
        string ageCat;
    public:
        //constructor?
        void setAgeCat(string a);
        string getAgeCat() const;
};

#endif