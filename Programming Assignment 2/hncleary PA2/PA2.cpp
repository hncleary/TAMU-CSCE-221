/*
Jeremy Brown, Hunter Cleary
CSCE221-507
PA2
PA2.cpp
*/
#include <sstream>
#include <iostream>
#include <fstream>
#include "sort.h"
int comparisons = 0;
std::vector<Flight> readFlights(std::string fileName);
using namespace std;
int main()
{
  /*
    first read flights in files using readFlights()
    descen10.csv	ascen10.csv     rand10.csv
    descen100.csv	ascen100.csv	rand100.csv
    descen1000.csv	ascen1000.csv	rand1000.csv
    descen10000.csv ascen10000.csv	rand10000.csv
  */
	vector<Flight> flightsrand10destselection = selection_sort(readFlights("rand10.csv"), ByDestination);
	vector<Flight> flightsrand10depselection = selection_sort(readFlights("rand10.csv"), ByDepartureTime);
	vector<Flight> flightsrand10destbubble = bubble_sort(readFlights("rand10.csv"), ByDestination);
	vector<Flight> flightsrand10depbubble = bubble_sort(readFlights("rand10.csv"), ByDepartureTime);
	vector<Flight> flightsrand10destinsertion = insertion_sort(readFlights("rand10.csv"), ByDestination);
	vector<Flight> flightsrand10depinsertion = insertion_sort(readFlights("rand10.csv"), ByDepartureTime);
    // then use each of the sorting functions on each of the generated vectors

	//output random10 destination selection
	ofstream SortedValues("SortedValues.csv");
	SortedValues << "rand10 byDestination Selection Sort" << endl;
	SortedValues << "Flight Number,Destination,Departure Time,GateNumber" << endl;
	for (Flight f : flightsrand10destselection) {
		SortedValues << f.flightNum << "," << f.destination << "," << f.departureTime << "," << f.gateNum << endl;
	}
	SortedValues << "*"<< endl;
	//output random10 departure selection
	SortedValues << "rand10 byDeparture Selection Sort" << endl;
	SortedValues << "Flight Number,Destination,Departure Time,GateNumber" << endl;
	for (Flight f : flightsrand10depselection) {
		SortedValues << f.flightNum << "," << f.destination << "," << f.departureTime << "," << f.gateNum << endl;
	}
	SortedValues << "*" << endl;
	//output random10 destination bubble
	SortedValues << "rand10 byDestination Bubble Sort" << endl;
	SortedValues << "Flight Number,Destination,Departure Time,GateNumber" << endl;
	for (Flight f : flightsrand10destbubble) {
		SortedValues << f.flightNum << "," << f.destination << "," << f.departureTime << "," << f.gateNum << endl;
	}
	SortedValues << "*" << endl;
	//output random10 departure bubble
	SortedValues << "rand10 byDeparture Bubble Sort" << endl;
	SortedValues << "Flight Number,Destination,Departure Time,GateNumber" << endl;
	for (Flight f : flightsrand10depbubble) {
		SortedValues << f.flightNum << "," << f.destination << "," << f.departureTime << "," << f.gateNum << endl;
	}
	SortedValues << "*" << endl;
	//output random10 destination insertion
	SortedValues << "rand10 byDestination Insertion Sort" << endl;
	SortedValues << "Flight Number,Destination,Departure Time,GateNumber" << endl;
	for (Flight f : flightsrand10destinsertion) {
		SortedValues << f.flightNum << "," << f.destination << "," << f.departureTime << "," << f.gateNum << endl;
	}
	SortedValues << "*" << endl;
	//output random10 departure insertion
	SortedValues << "rand10 byDeparture Insertion Sort" << endl;
	SortedValues << "Flight Number,Destination,Departure Time,GateNumber" << endl;
	for (Flight f : flightsrand10depinsertion) {
		SortedValues << f.flightNum << "," << f.destination << "," << f.departureTime << "," << f.gateNum << endl;
	}
	SortedValues << "*" << endl;
	SortedValues.close();
	
  return 0;
}

//read in the flights from the input file at fileName and store them in a vector
vector<Flight> readFlights(std::string fileName)
{
	vector<Flight> flights;
	ifstream file;
	file.open(fileName);
	string s;
	getline(file, s);
	while(!file.eof()) {
		string flightNum, destination, departureTime, gateNum;
		getline(file, flightNum, ',');
		getline(file, destination, ',');
		getline(file, departureTime, ',');
		getline(file, gateNum);
		if (gateNum != "")
		flights.push_back(Flight(flightNum, destination, departureTime, gateNum));
	}
	return flights;
}


/*
then output each of the resultant sorted vectors
format them so that they look like the table of the front of the
instructions

Flight Number	Destination Departure   Time	        Gate Number
AA223			LAS VEGAS	21:15			A3
BA023			DALLAS		21:00			A3
AA220			LONDON		20:30			B4
VI303			MEXICO		19:00			A7
BA087			LONDON		17:45			A7
AA342			PARIS		16:00			A7
VI309			PRAGUE		13:20			F2
QU607			TORONTO		08:30			F2
AA224			SYDNEY		08:20			A7
AF342			WASHINGTON	07:45			A3
*/