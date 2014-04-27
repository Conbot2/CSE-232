#include <map>
using std::map;
#include <vector>
using std::vector;
#include <string>
using std::string;

#ifndef __MARKET_H_INCLUDED__
#define __MARKET_H_INCLUDED__

struct Market
{
  map<long, vector<double>> stocks;
  vector<string> stock_names {"AA","AXP","BA","BAC","CAT","CSCO","CVX","DD","DIS","GE","HD","HPQ","IBM",
  "INTC","JNJ","JPM","KFT","KO","MCD","MMM","MRK","MSFT","PFE","PG","T","TRV","UTX","VZ","WMT","XOM"};
  double get_price(string, long);
  Market(string);
};

#endif