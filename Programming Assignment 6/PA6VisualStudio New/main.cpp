#include "my_map.h"
#include "text_freq.h"
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
int main()
{
	/*
    my_map<string, int> m;
    m["c"] = 10;
    m["f"] = 3;
    m["b"] = 4;
    m["a"] = 5;
    m["d"] = 15;
    m["e"] = 15;
    m["f"] = 15;
    
    cout << endl << m << endl;
    
    auto curr = m.begin();
    
    while(curr != m.end())
    {
        cout << *curr << endl;
        curr++;
    }
	*/
	remove_punctuation("C:\\Users\\Hunter\\Desktop\\CSCE 221\\Programming Assignment 6\\PA6_18A_handouts\\TFOTR.txt");
	create_freq_map("C:\\Users\\Hunter\\Desktop\\CSCE 221\\Programming Assignment 6\\PA6_18A_handouts\\TFOTR.txt");

	remove_punctuation("C:\\Users\\Hunter\\Desktop\\CSCE 221\\Programming Assignment 6\\PA6_18A_handouts\\test_text1.txt");
	create_freq_map("C:\\Users\\Hunter\\Desktop\\CSCE 221\\Programming Assignment 6\\PA6_18A_handouts\\test_text1.txt");

	system("pause");
}