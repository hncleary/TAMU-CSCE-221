#include "text_freq.h"
#include "my_map.h"
#include "key_value.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

string read_file(string file_name)
{
    //FINISH THIS FUNCTION
    //this should read the file, and return the string of the whole file
	//string file_name = file_name;
	std::ifstream inputFile("myfile.txt");
	std::string textString((std::istreambuf_iterator<char>(inputFile)),(std::istreambuf_iterator<char>()));
	return textString;
}

string remove_punctuation(string text)
{
	string result = text;
	/*
    string result;
    std::remove_copy_if(text.begin(), text.end(),            
                        std::back_inserter(result), //Store output           
                        std::ptr_fun<int, int>(&std::ispunct));
    return result;
	*/
	cout << "Remove Punctuation" << endl;
	return result;
}

void create_freq_map(string text)
{
    my_map<string,double> freq_map;

    //FINISH THIS FUNCTION
    //this should find the frequecies of every word in the text
	//map with string and int
	map<string, int> frequency;
	// pair for key and value in the map
	pair<string, int> textNumber;
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
	//inputFile.open("C:\\Users\\Hunter\\Desktop\\CSCE 221\\Programming Assignment 6\\PA6_18A_handouts\\TFOTR.txt");
	inputFile.open(text);
	// check whether the file exists or not
	// if not, display the error message and exit the program
	if (!inputFile)
	{
		cout << "Unable to open/read the file" << endl;
		//system("pause");
		//return 0;
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
		if (frequency.find(word) != frequency.end())
		{
			frequency[word]++;
		}
		// if not found, then set the key and its value to 1
		else
		{
			textNumber.first = word;
			textNumber.second = 1;
			frequency.insert(textNumber);
		}
	}
	inputFile.close();
	map<string, int>::iterator it;
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
	std::sort(v.begin(), v.end());
	std::reverse(v.begin(), v.end());


	vector<string> filterWords{ "the","and","of","to","a","in","was","he","I","that","it","is","as","for","had","on","with","at","were","but","The","be","we","if","or","no","But","It","He","are","so","its","'", "-" };
	for (unsigned i = 0; i < sv.size(); ++i) {
		for (unsigned j = 0; j < filterWords.size(); ++j) {
			if (sv.at(i) == filterWords.at(j)) {
				sv.erase(sv.begin() + i);
				vCopy.erase(vCopy.begin() + i);
			}
		}
	}

	cout << endl << endl << "Top 20 Most Frequent Words in "<< text << " "<< endl << "(Excluding words that are not consequential)"<< endl;
	cout << "Removed: the, and, of, to, a, in, was, he, I, that, it, is, as, for, had, on..." << endl << endl ;
	cout << "Frequency    ---       Word" << endl;
	cout << "---------------------------" << endl << endl;
	// TOP 20 Output
	for (int i = 0; i < 20; ++i) {
		// cout << *max_element(vCopy.begin(), vCopy.end()) << endl;
		int max_elem_position = distance(vCopy.begin(), max_element(vCopy.begin(), vCopy.end()));
		//cout << max_elem_position << " ";
		cout << vCopy.at(max_elem_position) << "          ---      " << sv.at(max_elem_position) << " " << endl;
		sv.erase(sv.begin() + max_elem_position);
		vCopy.erase(vCopy.begin() + max_elem_position);
	}
	cout << endl << endl;
    //return freq_map;
}

vector<key_value<string,double>> vectorize_map(my_map<string, double>& freq_map)
{
    vector<key_value<string,double>> freq_vec;

    //FINISH THIS FUNCTION
    //this should return a sorted vector of the results
	std::sort(freq_vec.begin(), freq_vec.end());
	std::reverse(freq_vec.begin(), freq_vec.end());
    return freq_vec;
}

void remove_stop_words(vector<key_value<string,double>>& freq_vec, vector<string> stop_words)
{
   //FINISH THIS FUNCTION
   //this function should remove the elements contained in stop_words from freq_vec 
	
	vector<string> filterWords{ "the","and","of","to","a","in","was","he","I","that","it","is","as","for","had","on","with","at","were","but","The","be","we","if","or","no","But","It","He","are","so","its","'", "-" };
	
	for (unsigned i = 0; i < freq_vec.size(); ++i) {
		for (unsigned j = 0; j < filterWords.size(); ++j) {
			if (filterWords.at(j) == filterWords.at(i)) {
				freq_vec.erase(freq_vec.begin() + i);
				//vCopy.erase(vCopy.begin() + i);
			}
		}
	}
	/*
	map<string, int>::iterator it;
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
	*/
	//cout << "Remove Stop Words..." << endl;
}

void print_top_20_freqs(const vector<key_value<string,double>>& freq_vec, ostream& out)
{
	/*
    //prints the top 20 frequencies to out
	for (int i = 0; i < 20; ++i) {
		// cout << *max_element(vCopy.begin(), vCopy.end()) << endl;
		int max_elem_position = 0;
		//int max_elem_position = distance(vCopy.begin(), max_element(vCopy.begin(), vCopy.end()));
		//cout << max_elem_position << " ";
		cout << vCopy.at(max_elem_position) << "          ---      " << sv.at(max_elem_position) << " " << endl;
		sv.erase(sv.begin() + max_elem_position);
		vCopy.erase(vCopy.begin() + max_elem_position);
	}
	*/
	vector<int> vCopy;
	vector<string> sv;
	for (int i = 0; i < 20; ++i) {
		// cout << *max_element(vCopy.begin(), vCopy.end()) << endl;
		int max_elem_position = distance(vCopy.begin(), max_element(vCopy.begin(), vCopy.end()));
		//cout << max_elem_position << " ";
		cout << vCopy.at(max_elem_position) << "          ---      " << sv.at(max_elem_position) << " " << endl;
		sv.erase(sv.begin() + max_elem_position);
		vCopy.erase(vCopy.begin() + max_elem_position);
	}
	//cout << "Print Top 20 Frequencies... " << endl;
}
