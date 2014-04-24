#include "rand_walk.h"
#include <iostream>
using std::cout; using std::cin; using std::endl;
#include <fstream>
using std::ifstream;
#include <map>
using std::map; using std::pair;
#include <vector>
using std::vector;
#include <string>
using std::string; using std::to_string;
#include <random>
using std::default_random_engine; using std::uniform_int_distribution;
#include <algorithm>
using std::sort; using std::find;
#include <cassert>

int main() {
  long total_walks = 10000;
  long walk_length = 10;
  int rand_seed = 123;
  string index_file_name = "example_nodes.txt";
  string arc_file_name="example_arcs.txt";
  default_random_engine eng(rand_seed);

  map<long,string> index_map;
  read_index(index_map, index_file_name);
  // checks to make sure we got index_map right
  assert(index_map[20]=="azspot.net");
  assert(index_map[0]=="1000notes.com");
  assert(index_map[105]=="zoomblog.com");

  map<long,vector<long>> arc_map;
  read_arc(arc_map, arc_file_name);
  // checks to make sure we got arc_map right
  auto arcs = arc_map[7];
  assert(find(arcs.begin(), arcs.end(), 5) != arcs.end());
  arcs = arc_map[102];
  assert(find(arcs.begin(), arcs.end(), 68) != arcs.end());
  arcs = arc_map[100];
  assert(find(arcs.begin(), arcs.end(), 105) == arcs.end());

  auto visit_count = do_walk(arc_map, index_map, total_walks, walk_length, eng);

  // ** to print visit_count nicely **
  // print in order of visits as website names, 
  vector<pair<string,long>> v;
  copy(visit_count.begin(), visit_count.end(), back_inserter(v));
  // sort it on second using >
  sort(v.begin(), v.end(), 
       [] (const pair<string,long> &p1, const pair<string,long> &p2)
       {return p1.second > p2.second;});
  //print new order
  for(auto &element : v)
    cout << element.first <<":"<<element.second<<endl;
    cout << endl;   
}

