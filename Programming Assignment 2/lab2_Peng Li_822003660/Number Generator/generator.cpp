// generator.cpp
// Author: Peng Li
// Date: Sep 24, 2014
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <vector>
#include <cmath>

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <stdio.h>

#include <sstream>
#include <iostream>
#include <fstream>
#include <algorithm>


const int NUM = 100000;

using namespace std;


int main(){
    srand(time(NULL));
    try{
        int output[NUM];
        
        ofstream fileout0 ("output_random");
        ofstream fileout1 ("output_increasing");
        ofstream fileout2 ("output_descreasing");
        
        // output number of lines
        fileout0 << NUM << endl;
        fileout1 << NUM << endl;
        fileout2 << NUM << endl;

        int range;
        range = pow(2,16)-1;
        int a =  pow(2,15);
        int num;
        for (int i = 0; i<NUM; i++) {
            num = rand() % range - a;
            output[i] = num;
            fileout0 << num << endl;
        }
        
        sort(output, output+NUM);
        for (int i = 0; i<NUM; i++) {
            fileout1 << output[i] << endl;
            fileout2 << output[NUM-1-i] << endl;
        }

        fileout0.close();
        fileout1.close();
        fileout2.close();
        return 0;


    }
    
    catch(exception &error){
        cerr << "Error: " << error.what() << endl;
    }
}
