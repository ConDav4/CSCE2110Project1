#include "experiencedriver.h"
using namespace std;
ExperienceDriver::ExperienceDriver(){
	expCat = "NULL";
}
ExperienceDriver::ExperienceDriver(string e){
	expCat = e;
}
void ExperienceDriver::setExpCat(string e) {
    expCat = e;
}

string ExperienceDriver::getExpCat() const {
    return expCat;
}
