#include <string>
using std::string;
#include <vector>
using std::vector;
#include <map>
using std::map;

string lower_and_strip(string s);

void read_stopwords(vector<string> &v, string file_name);

void read_file(map<string, long> &m, vector<string> &stop_list, string file_name);

string print_map(map<string, long> &m, string order="alpha");

vector<string> sorted_words(map<string, long> &m);

template<typename Itr1, typename Itr2, typename Out>
void my_set_intersection(Itr1 source1_begin, Itr1 source1_end, Itr2 source2_begin, Itr2 source2_end, Out dest) {
  string word;
  for (Itr1 it = source1_begin; it != source1_end; ++it) {
    word = *(find(source2_begin,source2_end,*it));
    if (word != *source2_end) {
      *dest = word;
      dest++;
    }
  }
}

template<typename Itr1, typename Itr2, typename Out>
void my_set_difference(Itr1 source1_begin, Itr1 source1_end, Itr2 source2_begin, Itr2 source2_end, Out dest) {
  string word;
  for (Itr1 it = source1_begin; it != source1_end; ++it) {
    word = *(find(source2_begin,source2_end,*it));
    if (word == *source2_end) {
      *dest = *it;
      dest++;
    }
  }
}