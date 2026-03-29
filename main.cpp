#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include "driver.h"
#include "address.h"
#include "date.h"
#include "agedriver.h"
#include "workdriver.h"
#include "experiencedriver.h"
#include "medicaldriver.h"
#include "ticket.h"
#include "driverlist.h"
#include "hashtable.h"
#include "databasesystem.h"
using namespace std;

// Today's date
time_t t = time(nullptr);
tm* now = localtime(&t);
int Tyear = now->tm_year + 1900;
int Tmonth = now->tm_mon + 1;
int Tday = now->tm_mday;
Date Today(Tday, Tmonth, Tyear);


void printMainMenu();
void printAddDriverTypeMenu();
void printAgeCatMenu();
void printWorkCatMenu();
void printExpCatMenu();
void printMedCatMenu();
Date readDate(const string& prompt);
Address readAddress(const string& prompt);
void fillBaseFields(Driver* d);
Driver* buildDriver();
void import(const string& filename, DatabaseSystem& db);

// Print Menu
void printMainMenu() {
	cout << "\n+--------------------------------------+" << endl;
	cout << "       THE DATABASE (or whatever)       " << endl;
	cout << "+--------------------------------------+" << endl;
	cout << "1. Add driver" << endl;
	cout << "2. Search for driver ID" << endl;
	cout << "3. Migrate to inactive (ID)" << endl;
	cout << "4. View recently issued" << endl;
	cout << "5. View oldest issued" << endl;
	cout << "6. Display active" << endl;
	cout << "0. Exit" << endl;
	cout << "+--------------------------------------+" << endl;
	cout << "Enter choice: " << endl; 
}

void printAddDriverTypeMenu() {
	cout << "\n~~~ Select Driver Category (placeholder names)~~~" << endl;
	cout << "1. Age" << endl;
	cout << "2. Work" << endl;
	cout << "3. Experience" << endl;
	cout << "4. Medical Con." << endl;
	cout << "5. No category" << endl;
	cout << "Enter choice: " << endl;
}

// Read date from input
Date readDate(const string& prompt) {
	int d, m, y;
	cout << prompt << " (dd mm yyyy): ";
	cin >> d >> m >> y;
	return Date(d, m, y);
}

// Read address from input
Address readAddress(const string& prompt) {
	string street, city, county, state;
	int zip;
	cout << prompt << endl;
	cin.ignore();
	cout << "  Street: ";	getline(cin, street);
	cout << "  City: ";		getline(cin, city);
	cout << "  County: ";	getline(cin, county);
	cout << "  State: ";	getline(cin,state);
	cout << "  ZIP: ";		cin >> zip;
	return Address(street, city, county, state, zip);
}

// Fill driver info
void fillBaseFields(Driver* d) {
	string id, name;
	cout << " Driver ID: ";		cin >> id;
	cout << " Name: ";			cin.ignore(); getline(cin, name);

	d->setDriverID(id);
	d->setName(name);

	Date dob = readDate("  Date of birth");
	d->setDOB(dob);
	
	Date lic = readDate("  License issue date");
	d->setLicenseIssueDate(lic);

	Address addr = readAddress("  Home address");
	d->setAddress(addr);

	char hasTicket;
	 cout << "  Does driver have a ticket? (y/n): ";
	 cin >> hasTicket;
	 if (hasTicket == 'y' || hasTicket == 'Y') {
		Date ticketDate = readDate("  Ticket issue date");
		Address ticketLoc = readAddress("  Ticket location");
		Ticket t(ticketDate, ticketLoc);
		d->setTicket(t);
		d->setTicketStatus(true);
	 } else {
		d->setTicketStatus(false);
	 }
}

// Age sub-menu
void printAgeCatMenu() {
	cout << "  Age categories:" << endl;
	cout << "    1. Youth (16-28)" << endl;
	cout << "    2. Middle-aged (28-50)" << endl;
	cout << "    3. Senior/Old age (50+)" << endl;
	cout << "  Choice: ";
}

// Work sub-menu
void printWorkCatMenu() {
	cout << "  Work categories:" << endl;
	cout << "    1. Student" << endl;
	cout << "    2. Government employee" << endl;
	cout << "    3. Self-employed" << endl;
	cout << "    4. Business owner" << endl;
	cout << "    5. Private sector employee" << endl;
	cout << "  Choice: " << endl;
}

// Experience sub-menu
void printExpCatMenu() {
	cout << "  Experience categories:" << endl;
	cout << "    1. New driver (0-5 years)" << endl;
	cout << "    2. Moderately experienced (5-15 years)" << endl;
	cout << "    3. Highly experienced (15+ years)" << endl;
	cout << "  Choice: " << endl;
}

// Medical sub-menu
void printMedCatMenu() {
	cout << "  Medical categories:" << endl;
	cout << "    1. Fit" << endl;
	cout << "    2. Vision impaired" << endl;
	cout << "    3. Upper extremity impairment" << endl;
	cout << "    4. Locomotor disability" << endl;
	cout << "  Choice: " << endl;
}

// Build driver from input
Driver* buildDriver() {
	printAddDriverTypeMenu();
	int typeChoice;
	cin >> typeChoice;

	Driver* d = nullptr;
	int subChoice;

	switch(typeChoice) {
		// Age
		case 1: {
			printAgeCatMenu();
			cin >> subChoice;
			string cat;
			if		(subChoice == 1) cat = "Youth";
			else if (subChoice == 2) cat = "Middle-aged";
			else					 cat = "Senior";
			d = new AgeDriver(cat);
			break;
		}
		// Work
		case 2: {
			printWorkCatMenu();
			cin >> subChoice;
			string cat;
			if		(subChoice == 1) cat = "Student";
			else if (subChoice == 2) cat = "Government employee";
			else if (subChoice == 3) cat = "Self-employed";
			else if (subChoice == 4) cat = "Business owner";
			else					 cat = "Private sector employee";
			d = new WorkDriver(cat);
			break;
		}
		// Experience
		case 3: {
			printExpCatMenu();
			cin >> subChoice;
			string cat;
			if		(subChoice == 1) cat = "New driver";
			else if (subChoice == 2) cat = "Moderately experienced";
			else					 cat = "Highly experienced";
			d = new ExperienceDriver(cat);
			break;
		}
		// Medical
		case 4: {
			printMedCatMenu();
			cin >> subChoice;
			string cat;
			if		(subChoice == 1) cat = "Fit";
			else if (subChoice == 2) cat = "Vision impaired";
			else if (subChoice == 3) cat = "Upper extremity impairment";
			else					 cat = "Locomotor disability";
			d = new MedicalDriver(cat);
			break;
		}
		// Base
		default:
			d = new Driver();
			break;
	}

	fillBaseFields(d);
	return d;
}

void import(const string& filename, DatabaseSystem& db) {
	ifstream file(filename);
	if (!file) {
		cout << "Error: could not open file: " << filename << endl;
		return;
	}
	string line;
	int count = 0;
	while (getline(file, line)) {
		if (line.empty()) continue;
		stringstream ss(line);
		string id, name, street, city, county, state, zip;
		string dobDay, dobMonth, dobYear;
		string licDay, licMonth, licYear;
		
		getline(ss, id, ',');
		getline(ss, name, ',');
		getline(ss, street, ',');
		getline(ss, city, ',');
		getline(ss, county, ',');
		getline(ss, state, ',');
		getline(ss, zip, ',');
		getline(ss, dobDay, ',');
		getline(ss, dobMonth, ',');
		getline(ss, dobYear, ',');
		getline(ss, licDay, ',');
		getline(ss, licMonth, ',');
		getline(ss, licYear, ',');

		Address addr(street, city, county, state, stoi(zip));
		Date    dob (stoi(dobDay), stoi(dobMonth), stoi(dobYear));
		Date    lic (stoi(licDay), stoi(licMonth), stoi(licYear));
		
		Driver* d = new Driver();
		d->setDriverID(id);
		d->setDriverName(name);
		d->setAddress(addr);
		d->setDOB(dob);
		d->setYearsExperience(d.getAge(Today, lic));
		d->setLicenseIssueDate(lic);
		db.addDriver(d);
		++count;
	}
	file.close();
	cout << count << " driver(s) imported from \"" << filename << "\"." << endl;
}



// MAIN
int main() {
	int numInput;
	string wordInput;
	bool running = true;

	do {
		//menu loop
		printMainMenu();
		cin >> numInput;

		switch (numInput){
			// Add manually
			case 1: {
				cout << "\n~~~ Add New Driver ~~~" << endl;
				Driver* d = buildDriver();
				db.addDriver(d);
				cout << "Driver added successfully." << endl;
				break;
			}

			// Import
			case 2: {
				cout << "\n~~~ Import Drivers from File ~~~" << endl;
				cout << "Enter filename: ";
				cin >> wordInput;
				import(wordInput, db);
				break;
			}

			// Search
			case 3: {
				cout << "\n~~~ Search Driver ~~~" << endl;
				cout << "Enter Driver ID: ";
				cin >> numInput;
				Driver* found = db.searchDriver(numInput);
				if (found) {
					cout << "\n~~~ Driver Found ~~~" << endl;
					found->displayDriver();
				}
				break;
			}

			// Migrate to inactive
			case 4: {
				cout << "\n~~~ Migrate Driver ~~~" << endl;
				cout << "Enter Driver ID to migrate: ";
				cin >> numInput;
				db.migrateDriver(numInput);
				break;
			}

			// Recently issued
			case 5: {
				cout << "\n~~~ Recent Licenses ~~~" << endl;
				cout << "Enter N: ";
				cin >> numInput;
				db.getRecentLicenses(numInput);
				break;
			}

			// Oldest issued
			case 6: {
				cout << "\n~~~ Oldest Licenses ~~~" << endl;
				cout << "Enter N: ";
				cin >> numInput;
				db.getOldestLicenses(numInput);
				break;
			}

			// Display all
			case 7: {
				cout << "\n~~~ All Active Drivers ~~~" << endl;
				for (int id = 1001; id <= 1010; id++) {
					Driver* d = db.searchDriver(id);
					if (d) {
						d->displayDriver();
						cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
					}
				}
				break;
			}
			// Exit
			case 0: {
				cout << "\nExiting. Goodbye!" << endl;
				running = false;
				break;
			}

			default: {
				cout << "\nInvalid choice. Please try again." << endl;
				break;
			}
		}
		
	} while (running);
	
	return 0;
}
