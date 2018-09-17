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
	remove_punctuation("TFOTR.txt");
	create_freq_map("TFOTR.txt");

	remove_punctuation("test_text1.txt");
	create_freq_map("test_text1.txt");

	//system("pause");
}