#include "madlib.h"
#include <string>
using std::string; using std::getline;
#include <vector>
using std::vector;
#include <random>
using std::default_random_engine; using std::uniform_int_distribution;
#include <fstream>
using std::ifstream; using std::ofstream;
#include <iostream>
using std::cin; using std::cout; using std::endl;


vector<string> load_word_file(string filename) {
    ifstream loadfile(filename);
    vector<string> words;
    string word;
    while (loadfile >> word)
        words.push_back(word);
    return words;
}

string random_word(vector<string>& my_vec, default_random_engine& my_engine) {
    // returns random word from vector
    long rand_num;
    string word;
    uniform_int_distribution<long> dist(0,my_vec.size()-1);
    rand_num = dist(my_engine);
    word = my_vec[rand_num];
    return word;
}

void split(string my_string, vector<string>& string_vec) {
    // fills vector with words from string, whitespace delimited
    long pos1 = 0;
    long pos2;
    string word;
    char my_char;
    for (long i = 0; i <= my_string.length(); i++) {
        my_char = my_string[i];
        if ((my_char == ' ') || (my_char == '\t') || (my_char == '\n') || (my_char == '\0')) {
            pos2 = my_string.find(my_char);
            word = my_string.substr(pos1,pos2 - pos1);
            string_vec.push_back(word);
            pos1 = pos2 + 1;
        }
    }
}

void process_document(string noun_file, string verb_file, string in_file, string out_file, int seed) {
    // replaces templates with words from file; writes to out_file
    ofstream ofile (out_file);
    ifstream ifile (in_file);
    string place;
    vector<string> nouns = load_word_file(noun_file);
    vector<string> verbs = load_word_file(verb_file);
    default_random_engine my_engine(seed);

    while (ifile >> place) {
        if (place == "<noun>")
            place = random_word(nouns,my_engine);
        else if (place == "<verb>")
            place = random_word(verbs,my_engine);
        ofile << place;
        if (place.back() == '.' || place.back() == '!' || place.back() == '?')
            ofile << '\n';
        else
            ofile << ' ';
    }
    ofile.close();
    ifile.close();
}