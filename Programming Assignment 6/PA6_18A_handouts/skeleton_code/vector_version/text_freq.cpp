#include "text_freq.h"
#include "my_map.h"
#include "key_value.h"
#include <fstream>
#include <sstream>
using namespace std;

string read_file(string file_name)
{
    //FINISH THIS FUNCTION
    //this should read the file, and return the string of the whole file
}

string remove_punctuation(string& text)
{
    string result;
    std::remove_copy_if(text.begin(), text.end(),            
                        std::back_inserter(result), //Store output           
                        std::ptr_fun<int, int>(&std::ispunct));
    return result;
}

my_map<string, double> create_freq_map(const string& text)
{
    my_map<string,double> freq_map;

    //FINISH THIS FUNCTION
    //this should find the frequecies of every word in the text

    return freq_map;
}

vector<key_value<string,double>> vectorize_map(my_map<string, double>& freq_map)
{
    vector<key_value<string,double>> freq_vec;

    //FINISH THIS FUNCTION
    //this should return a sorted vector of the results

    return freq_vec;
}

void remove_stop_words(vector<key_value<string,double>>& freq_vec, vector<string> stop_words)
{
   //FINISH THIS FUNCTION
   //this function should remove the elements contained in stop_words from freq_vec 
}

void print_top_20_freqs(const vector<key_value<string,double>>& freq_vec, ostream& out)
{
    //prints the top 20 frequencies to out
}
