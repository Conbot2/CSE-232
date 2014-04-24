#include "rand_walk.h"
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <fstream>
using std::ifstream;
using std::uniform_int_distribution;


void read_index(map<long, string> &m, string &file_name) {
  // create map containing website name and ID
  ifstream index(file_name);
  string site;
  long id;
  while (index >> site >> id)
    m[id] = site;
  index.close();
}

void read_arc(map<long, vector<long>> &m, string &file_name) {
  // create map containing nodes and connected arcs
  ifstream arcs(file_name);
  long start, end;
  
  while (arcs >> start >> end)
    m[start].push_back(end);
  arcs.close();
}

long select(default_random_engine &dre, vector<long> &container) {
  // returns a random value from container
  long rand_num, index;
  uniform_int_distribution<long> dist(0,container.size()-1);
  index = dist(dre);
  rand_num = container[index];
  return rand_num;
}

map<string, long> do_walk(map<long, vector<long>> &arc_map, map<long, string> &index_map, long total_walks, long walk_length, default_random_engine &dre) {
  // does total_walks random walks of length walk_length
  map<string, long> visit_count;
  long index, out_arc;
  string current_site;
  uniform_int_distribution<long> dist(0,index_map.size()-1);

  for (long i = 0; i <= total_walks; i++) {
    index = dist(dre);
    for (long l = 0; l <= walk_length; l++) {
      current_site = index_map[index];
      ++visit_count[current_site];
      vector<long> &site_arcs = arc_map[index];
      if (site_arcs.empty()) {    // end walk if no connections
        break;
      }
      else {
        out_arc = select(dre,site_arcs);
        index = out_arc;
      }
    }
  }
  return visit_count;
}