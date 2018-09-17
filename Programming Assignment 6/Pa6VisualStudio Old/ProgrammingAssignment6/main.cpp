#include "my_map.h"
#include <iostream>
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
	create_freq_map("C:\\Users\\Hunter\\Desktop\\CSCE 221\\Programming Assignment 6\\PA6_18A_handouts\\TFOTR.txt");
}