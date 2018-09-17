#include "BTree.h"
#include <iostream>
#include <fstream>

template<typename T>
BTree<T> read_file(string file_name);

using namespace std;

int main()
{
	ifstream file_read;
	file_read.open("12p");
	int data;
	int totalNodes = 0;
	vector<int> inputData;
	if (file_read.is_open())
	{

		cout << "Input Data: \n";
		while (file_read >> data) {
			//totalNodes++;
			//inputData.push_back(data);
			cout << data << endl;
		}
		file_read.close();
	}

	//BTree<int> new_tree = read_file<int>("12p");
	system("pause");
}

template<typename T>
BTree<T> read_file(string file_name)
{
    /*
        open the file and use the input operator (operator>>)
        to construct a new tree
    */
    BTree<T> new_tree;
	ifstream file_read;

	file_read.open(file_name);
	int data;
	int totalNodes = 0;
	vector<int> inputData;
	if (file_read.is_open())
	{

		cout << "Input Data: \n";
		while (file_read >> data) {
			totalNodes++;
			inputData.push_back(data);
			cout << data << endl;
		}
		file_read.close();
	}

	for (size_t i = 0; i < inputData.size(); ++i) {
		new_tree.insert(inputData[i]);
	}
	
    return new_tree;
}
