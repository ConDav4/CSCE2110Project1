#ifndef NODE_H
#define NODE_H
#include "driver.h"
using namespace std;

class Node {
    public:
        Node *next, *prev;
        Driver *data;
        Node(Driver* d);
        Node();
};

#endif