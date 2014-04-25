#include <iostream>
using std::cout; using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <map>
using std::map;
#include <algorithm>
using std::find; using std::set_intersection; using std::set_difference;
#include <iterator>
using std::ostream_iterator;
#include <cassert>
#include "functions.h"

int main () {

  map<string, long> gburg;
  map<string, long> decl;
  vector<string> stop_list;
  vector<string> result;
  string test;

  test = lower_and_strip(",,abc::?");
  assert(test=="abc");
  test = lower_and_strip(" I CAN'T, ");
  assert(test=="i can't");

  read_stopwords(stop_list, "stopWords.txt");
  assert(find(stop_list.begin(), stop_list.end(), "according") != stop_list.end());
  assert(find(stop_list.begin(), stop_list.end(), "devotion") == stop_list.end());

  read_file(gburg, stop_list, "Gettysburg.txt");
  assert(gburg.count("devotion") != 0);
  assert(gburg.count("now") == 0);
  assert(gburg.count("God") == 0);  
  assert(gburg.count("god") != 0);  

  read_file(decl, stop_list, "Preamble.txt");
  assert(decl.count("Creator")==0);
  assert(decl.count("creator")!=0);
  assert(decl.count("this")==0);

  string alpha_order = print_map(gburg, "alpha");
  auto loc = alpha_order.find_first_of("abcdefghijklmnopqrstuvwxyz");
  assert(alpha_order.substr(loc, 3) == "add");
  cout << alpha_order << endl << endl << endl;

  string count_order = print_map(gburg, "count");
  loc = count_order.find_last_of("abcdefghijklmnopqrstuvwxyz");
  assert(count_order.substr(loc-5, 6) == "nation");
  cout << count_order << endl;

  vector<string> gburg_words = sorted_words(gburg);
  assert(gburg_words[0]=="add");
  assert(gburg_words[gburg_words.size()-1] == "years");
  vector<string> decl_words = sorted_words(decl);

  result.clear();
  my_set_intersection(gburg_words.begin(), gburg_words.end(),
			  decl_words.begin(), decl_words.end(),
			  back_inserter(result));

  copy(result.begin(), result.end(), ostream_iterator<string>(cout, ",")); cout << endl << endl;  
  assert(result[0]=="created");
  assert(result[result.size()-1] == "world");


  result.clear();
  my_set_difference(gburg_words.begin(), gburg_words.end(),
			  decl_words.begin(), decl_words.end(),
			  back_inserter(result));
  copy(result.begin(), result.end(), ostream_iterator<string>(cout, ",")); cout << endl << endl;
  assert(result[0]=="add");
  assert(result[result.size()-1] == "years");
}



  
