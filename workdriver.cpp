#include "workdriver.h"
using namespace std;

WorkDriver::WorkDriver(){
	workCat = "NULL";
}
WorkDriver::WorkDriver(string w) {
	workCat = w;
}

void WorkDriver::setWorkCat(string w) {
    workCat = w;
}

string WorkDriver::getWorkCat() const {
    return workCat;
}
