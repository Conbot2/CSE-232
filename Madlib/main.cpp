#include "madlib.h"
#include <iostream>
using std::cout; using std::cin; using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <random>
using std::default_random_engine;
#include <map>
using std::map;
using std::size_t;


int main() {
  // Test the load_word_file function
  string load_test;
  cout << "Please enter the word test file: ";
  cin >> load_test;
  auto words = load_word_file(load_test);
  cout << load_test << " has " << words.size() << " words" << endl;

  // Test the random_word function
  map<string, int> counts;
  default_random_engine engine;
  for (size_t i=0; i < words.size() * 100; i++) {
    string word = random_word(words, engine);
    counts[word] += 1;
  }
  cout << "random_word gave this distribution" << endl;
  for (auto pairing: counts) {
    cout << "  " << pairing.first << " returned "
         << pairing.second << " times" << endl;
  }

  // Test the split function
  string test_string = "this is\ta\ntest";
  vector<string> pieces;
  split(test_string, pieces);
  cout << "Split made " << pieces.size() << " pieces" << endl;

  // Calls the actual Mad Lib program.
  string noun, verb, input, output;
  int seed;
  cout << "Please enter the noun file: ";
  cin >> noun;
  cout << "Please enter the verb file: ";
  cin >> verb;
  cout << "Please enter the input file: ";
  cin >> input;
  cout << "Please enter the output file: ";
  cin >> output;
  cout << "Please enter the seed: ";
  cin >> seed;
  if (seed < 0) {
    cout << "Using Default" << endl;
    process_document(noun, verb, input, output);
  } else {
    process_document(noun, verb, input, output, seed);
  }
  cout << "Complete" << endl;
  return 0;
}
