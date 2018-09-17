/*
Jeremy Brown, Hunter Cleary
CSCE221-507
PA2
sort.cpp
*/

#include "sort.h"

//use this to keep track of comparisons
int num_cmps;

std::vector<Flight> selection_sort(std::vector<Flight> flights,
				   SortOption sortOpt)
{
	int comparisons = 0;
	if (sortOpt == ByDestination) {
		for (int macro = 0; macro < flights.size()-1; macro++) {
			int min = macro;
			for (int i = macro; i < flights.size(); i++) {
				comparisons++;
				if (compareToDestination(flights.at(min), flights.at(i)))
					min = i;
			}
			//swap min and macro
			{
				Flight temp = flights.at(min);
				flights.at(min) = flights.at(macro);
				flights.at(macro) = temp;
			}
		}
	}
	else {
		for (int macro = 0; macro < flights.size() - 1; macro++) {
			int min = macro;
			for (int i = macro; i < flights.size(); i++) {
				comparisons++;
				if (compareToDepartureTime(flights.at(min), flights.at(i)))
					min = i;
			}
			//swap min and macro
			{
				Flight temp = flights.at(min);
				flights.at(min) = flights.at(macro);
				flights.at(macro) = temp;
			}
		}
	}
	//flights.push_back(Flight(std::to_string(comparisons), "", "", ""));
	return flights;
}

std::vector<Flight> insertion_sort(std::vector<Flight> flights,
				   SortOption sortOpt)
{
	bool swap = true;
	int comparisons = 0;
	if(sortOpt == ByDestination)
	for (int macro = 1; macro < flights.size(); macro++) {
		swap = true;
		for (int i = macro; i > 0 && swap; i--) {
			comparisons++;
			if (!compareToDestination(flights.at(i), flights.at(i - 1))) {
				Flight temp = flights.at(i);
				flights.at(i) = flights.at(i - 1);
				flights.at(i - 1) = temp;
			}
			else
				swap = false;
		}
	}
	else {
		for (int macro = 1; macro < flights.size(); macro++) {
			swap = false;
			for (int i = macro; i > 0 && swap; i--) {
				comparisons++;
				if (!compareToDepartureTime(flights.at(i), flights.at(i - 1))) {
					swap = true;
					Flight temp = flights.at(i);
					flights.at(i) = flights.at(i - 1);
					flights.at(i - 1) = temp;
				}
			}
		}
	}
	//flights.push_back(Flight(std::to_string(comparisons), "", "", ""));
	return flights;
}

std::vector<Flight> bubble_sort(std::vector<Flight> flights, SortOption sortOpt)
{
	bool swap = true;
	int comparisons = 0;
	if (sortOpt == ByDestination) {
		for (int macro = flights.size() - 1; macro > 0 && swap; macro--) {
			swap = false;
			for (int i = 0; i < macro; i++) {
				comparisons++;
				if (compareToDestination(flights.at(i), flights.at(i + 1))) {
					swap = true;
					Flight temp = flights.at(i);
					flights.at(i) = flights.at(i + 1);
					flights.at(i + 1) = temp;
				}
			}
		}
	}
	else
	{
		for (int macro = flights.size() - 1; macro > 0 && swap; macro--) {
			swap = false;
			for (int i = 0; i < macro; i++) {
				comparisons++;
				if (compareToDepartureTime(flights.at(i), flights.at(i + 1))) {
					swap = true;
					Flight temp = flights.at(i);
					flights.at(i) = flights.at(i + 1);
					flights.at(i + 1) = temp;
				}
			}
		}
	}
		//flights.push_back(Flight(std::to_string(comparisons), "","", ""));
	return flights;
}