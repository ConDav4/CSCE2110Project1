#include "agedriver.h"
using namespace std;
AgeDriver::AgeDriver(){
	ageCat = "NULL";
}
void AgeDriver::setAgeCat(string a) {
    ageCat = a;
}

string AgeDriver::getAgeCat() const {
    return ageCat;
}
