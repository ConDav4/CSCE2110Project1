#include "experiencedriver.h"
using namespace std;
ExperienceDriver::ExperienceDriver(){
	expCat = "NULL";
}
void ExperienceDriver::setExpCat(string e) {
    expCat = e;
}

string ExperienceDriver::getExpCat() const {
    return expCat;
}
