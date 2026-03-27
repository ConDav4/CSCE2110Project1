#ifndef WORKDRIVER_H
#define WORKDRIVER_H
#include "driver.h"
using namespace std;

class WorkDriver : public Driver {
    protected:
        string workCat;
    public:
        WorkDriver(){
			workCat = "Null";
		}
        void setWorkCat(string w);
        string getWorkCat() const;
};

#endif
