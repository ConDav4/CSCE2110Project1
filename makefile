all: GroupProject
CXX = g++
CFLAGS = -Wall -g

GroupProject: date.o driver.o driverlist.o experiencedriver.o hashtable.o main.o medicaldriver.o node.o ticket.o workdriver.o address.o agedriver.o databasesystem.o
	$(CXX) $(CFLAGS) -o GroupProject date.o driver.o driverlist.o experiencedriver.o hashtable.o main.o medicaldriver.o node.o ticket.o workdriver.o address.o agedriver.o databasesystem.o

date.o: date.cpp date.h
	$(CXX) $(CFLAGS) -c date.cpp

driver.o: driver.cpp driver.h
	$(CXX) $(CFLAGS) -c driver.cpp

driverlist.o: driverlist.cpp driverlist.h 
	$(CXX) $(CFLAGS) -c driverlist.cpp

experiencedriver.o: experiencedriver.cpp experiencedriver.h 
	$(CXX) $(CFLAGS) -c experiencedriver.cpp

hashtable.o: hashtable.cpp hashtable.h 
	$(CXX) $(CFLAGS) -c hashtable.cpp

main.o: main.cpp
	$(CXX) $(CFLAGS) -c main.cpp

medicaldriver.o: medicaldriver.cpp medicaldriver.h
	$(CXX) $(CFLAGS) -c medicaldriver.cpp

node.o: node.cpp node.h
	$(CXX) $(CFLAGS) -c node.cpp

ticket.o: ticket.cpp ticket.h
	$(CXX) $(CFLAGS) -c ticket.cpp

workdriver.o: workdriver.cpp workdriver.h
	$(CXX) $(CFLAGS) -c workdriver.cpp

address.o: address.cpp address.h
	$(CXX) $(CFLAGS) -c address.cpp

agedriver.o: agedriver.cpp agedriver.h
	$(CXX) $(CFLAGS) -c agedriver.cpp

databasesystem.o: databasesystem.cpp databasesystem.h
	$(CXX) $(CFLAGS) -c databasesystem.cpp
	
clean:
	rm *.o GroupProject
