#include "node.h"
using namespace std;

Node::Node(Driver* d) {
    data = d;
    next = nullptr;
    prev = nullptr;
}

Node::Node() {
    data = nullptr;
    next = nullptr;
    prev = nullptr;
}