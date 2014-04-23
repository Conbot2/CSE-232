#include <string>
using std::string;
#include <vector>
using std::vector;
#include <random>
using std::default_random_engine;

vector<string> load_word_file(string filename);

string random_word(vector<string>&, default_random_engine&);

void split(string, vector<string>&);

void process_document(string noun_file, string verb_file, string in_file, string out_file, int seed = 98765);