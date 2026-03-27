#include "medicaldriver.h"
using namespace std;

MedicalDriver::MedicalDriver(){
	medicalCat = "NULL";
}
void MedicalDriver::setMedicalCat(string m) {
    medicalCat = m;
}

string MedicalDriver::getMedicalCat() const {
    return medicalCat;
}
