#include <string>
using std::string;
#include <vector>
using std::vector;
#include <map>
using std::map;
#include <random>
using std::default_random_engine;

void read_index(map<long, string> &m, string &file_name);

void read_arc(map<long, vector<long>> &m, string &file_name);

long select(default_random_engine &dre, vector<long> &container);

map<string, long> do_walk(map<long, vector<long>> &arc_map, map<long, string> &index_map, long total_walks, long walk_length, default_random_engine &dre);