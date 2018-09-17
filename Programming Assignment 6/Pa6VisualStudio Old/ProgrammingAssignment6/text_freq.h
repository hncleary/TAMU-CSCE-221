#ifndef TEXT_FREQ_H
#define TEXT_FREQ_H

#include "my_map.h"
#include "key_value.h"
#include <iterator> 
#include <vector>
#include <algorithm>
string read_file(string file_name);
string remove_punctuation(string& text);
my_map<string, double> create_freq_map(const string& text);
vector<key_value<string,double>> vectorize_map(my_map<string, double>& freq_map);
void remove_stop_words(vector<key_value<string,double>>& freq_vec, vector<string> stop_words);
void print_top_20_freqs(const vector<key_value<string,double>>& freq_vec, ostream& out);

#endif