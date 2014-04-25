// #include <cctype>
#include <string>
using std::string; using std::to_string;
#include <fstream>
using std::ifstream;
#include <vector>
using std::vector;
#include <map>
using std::map;
#include <algorithm>
using std::find; using std::sort;
#include <utility>
using std::pair;

string lower_and_strip(string s) {
  string target = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890";
  string sub;
  bool has_target = false;
  for (auto elem : s) {
    if (isalpha(elem) || isdigit(elem))
      has_target = true;
  }
  if (has_target) {    // if target found, strip and lower
    long pos1 = s.find_first_of(target);
    long pos2 = s.find_last_of(target);
    sub = s.substr(pos1, pos2 - pos1 + 1);
    for (long i = 0; i <= sub.length(); ++i)
      sub[i] = tolower(sub[i]);
  }
  else
    sub = s;
  return sub;
}

void read_stopwords(vector<string> &v, string file_name) {
  ifstream word_file;
  string word;
  word_file.open(file_name);
  while (word_file >> word) {
    v.push_back(word);
  }
  word_file.close();
}

void read_file(map<string, long> &m, vector<string> &stop_list, string file_name) {
  ifstream infile;
  string word, temp;
  vector<string>::iterator it;
  infile.open(file_name);
  while (infile >> word) {
    temp = lower_and_strip(word);
    it = find(stop_list.begin(),stop_list.end(),temp);
    if (it == stop_list.end())
      ++m[temp];
  }
  infile.close();
}

bool comparison(pair<string,long> p1, pair<string,long> p2) {
  return p1.second < p2.second;
}

string print_map(map<string, long> &m, string order="alpha") {
  string pairs;
  vector<pair<string,long>> pair_vec;
  for (auto elem : m)
    pair_vec.push_back(elem);
  if (order == "count")
    sort(pair_vec.begin(),pair_vec.end(),comparison);
  for (auto elem : pair_vec)
    pairs += ('(' + elem.first + ',' + to_string(elem.second) + "),");
  pairs.pop_back();
  return pairs;
}

vector<string> sorted_words(map<string,long> &m) {
  vector<string> words;
  for (auto elem : m)
    words.push_back(elem.first);
  sort(words.begin(),words.end());
  if (words[0] == "-" || words[0] == "--")
    words.erase(words.begin());
  return words;
}