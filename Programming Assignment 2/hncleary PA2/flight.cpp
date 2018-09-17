/*
  Jeremy Brown, Hunter Cleary
  CSCE221-507
  PA2
  Flight.cpp
*/

#include "flight.h"

Flight::Flight()
{}

Flight::Flight(std::string fn, std::string dest, std::string dt, std::string gn)
{
	flightNum = fn;
	destination = dest;
	departureTime = dt;
	gateNum = gn;
}

Flight::~Flight()
{
		flightNum = destination = departureTime = gateNum = "";
}

bool compareToDestination(Flight f1, Flight f2)
{
	int e = f1.destination.length();
	if (f2.destination.length() < e)
		e = f2.destination.length();
	for (int i = 0; i < e; i++) {
		if (f1.destination[i] < f2.destination[i])
			return false;
		else if (f1.destination[i] > f2.destination[i])
			return true;
	}
  return e == f2.destination.length();//if f1 is larger return true
}

bool compareToDepartureTime(Flight f1, Flight f2)
{
		int t1 = f1.departureTime[0] * 10 + f1.departureTime[1];
		int t2 = f2.departureTime[0] * 10 + f2.departureTime[1];
		if (t1 == t2) {//if hours are the same go to minutes
			t1 = f1.departureTime[3] * 10 + f1.departureTime[4];
			t2 = f2.departureTime[3] * 10 + f2.departureTime[4];
		}
		return t1 >= t2;
}
