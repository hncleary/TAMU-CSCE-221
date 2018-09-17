// include the required header files
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

// declare an helper function
bool checkWordInMap(map<string, int> frequency, string word);

// main function
int main()
{
	//map with string and int
	map<string, int> frequency;
	// pair for key and value in the map
	pair<string, int> pairWordCount;
	// string for filename
	string fileName;
	// to hold the each word read from the text file
	string word;

	ifstream inputFile;

	//cout << "Enter input file name: ";
	// read the file name
	//cin >> fileName;
	//cout << endl;
	// open the file
	//inputFile.open("C:\\Users\\Hunter\\Desktop\\CSCE 221\\Programming Assignment 6\\PA6_18A_handouts\\test_text_small1.txt");
	inputFile.open("C:\\Users\\Hunter\\Desktop\\CSCE 221\\Programming Assignment 6\\PA6_18A_handouts\\TFOTR.txt");
	// check whether the file exists or not
	// if not, display the error message and exit the program
	if (!inputFile)
	{
		cout << "Unable to open/read the file. Please try later.\n";
		system("pause");
		return 0;
	}
	//std::string str((std::istreambuf_iterator<char>(inputFile)),std::istreambuf_iterator<char>());
	/*
	string str, strTotal;
	getline(inputFile, str);
	while (inputFile) {
		strTotal += str;
		getline(inputFile, str);
	}
	*/
	//cout << strTotal << endl;
	
	// if the inputFile opens up then read the each word and find the existance
	// of the word in the map and increment the counter value
	while (!inputFile.eof())
	{
		// read the word
		inputFile >> word;
		/*
		if (frequency.find(word) == frequency.end())
			return false;
		// otherwise return true
		else
			return true;
		*/
		if(frequency.find(word) != frequency.end())
		{
			frequency[word]++;
		}
		// if not found, then set the key and its value to 1
		else
		{
			// set the pairWordCount variables' first and
			// second values
			pairWordCount.first = word;
			pairWordCount.second = 1;

			// insert the pairWordCount to map
			frequency.insert(pairWordCount);
		}
	}
	// close the file
	inputFile.close();
	// define the map iterator as it
	map<string, int>::iterator it;

	/////////////////////
	//IMPORTANT DONT DELETE
	/*
	for (it = frequency.begin(); it != frequency.end(); ++it)
	{
		cout << setfill(' ') << setw(20) << it->first << setw(15) << it->second << endl;
	}
	*/
	////////////////////////


	typedef map <string, int> MapType;
	MapType m;
	vector <int> v;
	vector <string> sv;

	// populate map somehow

	for (MapType::iterator it = frequency.begin(); it != frequency.end(); ++it) {
		v.push_back(it->second);
		sv.push_back(it->first);
		// cout << it->second << " ";
	}

	//std::sort(v.begin(), v.end() );
	// std::reverse(v.begin(), v.end());
	/*
	cout << "Unsorted V" << endl;
	for (int i = 0; i < v.size(); ++i) {
		cout << v.at(i) << " ";
	}
	cout << endl;
	*/

	// sort vector V
	vector<int> vCopy = v;
	std::sort(v.begin(),v.end());
	std::reverse(v.begin(), v.end());


	vector<string> filterWords{ "the","and","of","to","a","in","was","he","I","that","it","is","as","for","had","on","with","at","were","but","The","be","we","if","or","no","But","It","He","are","so","its","'", "-" };
	for (int i = 0; i < sv.size(); ++i) {
		for (int j = 0; j < filterWords.size(); ++j) {
			if (sv.at(i) == filterWords.at(j)) {
				sv.erase(sv.begin() + i);
				vCopy.erase(vCopy.begin() + i);
			}
		}
	}

	cout << "Most Frequent Words" << endl << endl;
	cout << "Frequency --- Word" << endl;
	// TOP 20 Output
	for (int i = 0; i < 100; ++i) {
		// cout << *max_element(vCopy.begin(), vCopy.end()) << endl;
		int max_elem_position = distance(vCopy.begin(), max_element(vCopy.begin(), vCopy.end()));
		//cout << max_elem_position << " ";
		cout << vCopy.at(max_elem_position) << "          ---      " << sv.at(max_elem_position) << " " << endl;
		sv.erase(sv.begin() + max_elem_position);
		vCopy.erase(vCopy.begin() + max_elem_position);
	}

	system("pause");
	return 0;
}
