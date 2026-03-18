#include "medicaldriver.h"
using namespace std;

void MedicalDriver::setMedicalCat(string m) {
    medicalCat = m;
}

string MedicalDriver::getMedicalCat() const {
    return medicalCat;
}