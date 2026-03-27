#include "workdriver.h"
using namespace std;

WorkDriver::WorkDriver(){
	workCat = "NULL";
}

void WorkDriver::setWorkCat(string w) {
    workCat = w;
}

string WorkDriver::getWorkCat() const {
    return workCat;
}
