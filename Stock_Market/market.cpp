#include "market.h"
#include <fstream>
using std::ifstream;
#include <sstream>
using std::istringstream;
#include <algorithm>
using std::find;

Market::Market(string filename) {
  // fill stocks map
  ifstream dowfile (filename);
  string line, sub;
  long date;
  double price;
  while (getline(dowfile,line)) {
    sub = line.substr(0,8);
    date = atol(sub.c_str());
    line.erase(0,13);               // leave only prices to read in
    istringstream iss(line);
    do {
      string number;
      iss >> number;
      if (number != "") {
        price = atof(number.c_str());
        stocks[date].push_back(price);
      }
    } while (iss);
  }
  dowfile.close();

  // remove extra prices at end of vector
  for (auto elem : stocks) {
    vector<double> &r = elem.second;
    elem.second.erase(elem.second.begin()+30,elem.second.end());
  }
}

double Market::get_price(string stock, long date) {
  // returns price for abbreviated stock name on provided date
  double price;
  long stock_ind = find(stock_names.begin(),stock_names.end(),stock) - stock_names.begin();
  if (stock_ind == 30 || stocks.count(date) == 0)
    price = -1.0;
  else {
    for (auto elem : stocks) {
      if (elem.first == date) {
        price = elem.second[stock_ind];
        break;
      }
    }
  }
  return price;
}