#include "driverlist.h"
#include <iostream>
#include <string>
using namespace std;

DriverList::DriverList(){
	head = nullptr;
	tail = nullptr;
	size = 0;
}
DriverList::~DriverList(){
	Node* cur = head;
	while(cur) {
		Node* next = cur->next;
		delete cur;
		cur = next;
	}
}

void DriverList::insertAtHead(Driver* d){
	Node* n = new Node(d);
	if(!head){
		head = tail = n;
	} else {
		n->next = head;
		head->prev = n;
		head = n;
	}
	++size;
}

void DriverList::insertAtTail(Driver* d) {
	Node* n = new Node(d);
	if(!tail) {
		head = tail = n;
	} else {
		tail->next = n;
		n->prev = tail;
		tail = n;
	}
	++size;
}

void DriverList::insertAtMiddle(Driver* d) {
	if(!head || !head->next) {
		insertAtTail(d);
		return;
	}
	int mid = size / 2;
	Node* cur = head;
	for(int i=0; i<mid && cur; ++i) {
		cur = cur->next;
	}
	if(!cur){
		insertAtTail(d);
		return;
	}
	Node* n = new Node(d);
	n->next = cur->next;
	n->prev = cur;
	if(cur->next) cur->next->prev = n;
	cur->next = n;
	if (cur == tail) {
		tail = n;
	}
	++size;
}

void DriverList::insertByCounty(Driver* d, string co) {
	if(!head) {
		insertAtHead(d);
		return;
	}
	Node* cur = head;
	while(cur) {
		if(cur->data && cur->data->getAddress().getCounty() == co) {
			Node * n = new Node(d);
			n->next = cur->next;
			n->prev = cur;
			if (cur->next) cur->next->prev = n;
			else tail=n;
			cur->next = n;
			++size;
			return;
		}
		cur = cur->next;
	}
	if(!cur){
		cout<<"No matching county: put at end."<<endl;
		insertAtTail(d);
	}
}

void DriverList::deleteDriver(int DriverID) {
	string id = to_string(DriverID);
	Node* cur = head;
	while(cur) {
		if (cur->data && cur->data->getDriverID() == id) {
			if(cur->prev) {
				cur->prev->next = cur->next;
			} else {
				head = cur->next;
			}
		if (cur->next) {
			cur->next->prev = cur->prev;
		} else {
			tail = cur->prev;
		}
		delete cur;
		--size;
		return;
		}
		cur = cur-> next;
	}
}

void DriverList::printRecentN(int n) const {
	Node* cur = tail;
	int count = 0;
	
	while(cur && count < n) {
		cout<<n<<": ";
		cur->data->displayDriver();
		cout<<endl;
		cur = cur->prev;
		count++;
	}
}

void DriverList::printOldestN(int n) const {
	Node* cur = head;
	int count = 0;
	
	while (cur && count < n) {
		cout<<n<<": ";
		cur->data->displayDriver();
		cout<<endl;
		cur= cur->next;
		count++;
	}
}

Driver* DriverList::searchDriver(int DriverID) {
	string id = to_string(DriverID);
	Node* cur = head;
	while(cur) {
		if (cur->data && cur->data->getDriverID() == id) {
			return cur->data;
		}
		cur = cur->next;
	}
	return nullptr;
}

void DriverList::printAll() const {
	Node* cur = head;
	while (cur) {
		if(cur->data) {
			cur->data->displayDriver();
		}
		cur = cur -> next;
	}
}

Node* DriverList::getHead() const {
	return head;
}

int DriverList::getSize() const {
	return size;
}
