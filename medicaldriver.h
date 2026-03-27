#ifndef MEDICALDRIVER_H
#define MEDICALDRIVER_H
#include "driver.h"
using namespace std;

class MedicalDriver : public Driver {
    protected:
        string medicalCat;
    public:
		MedicalDriver();
        void setMedicalCat(string m);
        string getMedicalCat() const;
};

#endif
