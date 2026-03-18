#ifndef EXPERIENCEDRIVER_H
#define EXPERIENCEDRIVER_H
#include "driver.h"
using namespace std;

class ExperienceDriver : public Driver {
    protected:
        string expCat;
    public:
        //constructor?
        void setExpCat(string e);
        string getExpCat() const;
};

#endif