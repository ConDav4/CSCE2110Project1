#include "node.h"
using namespace std;

Node::Node(Driver* d) {
    data = d;
    next = nullptr;
    prev = nullptr;
}