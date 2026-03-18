#include "workdriver.h"
using namespace std;

void WorkDriver::setWorkCat(string w) {
    workCat = w;
}

string WorkDriver::getWorkCat() const {
    return workCat;
}