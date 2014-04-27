#include <string>
using std::string;
#include <map>
using std::map;
#include "market.h"

#ifndef __PLAYER_H_INCLUDED__
#define __PLAYER_H_INCLUDED__

struct Player
{
  double cash;
  map<string, long> stocks;
  Player(double);
  bool buy(Market &m, string stock, long date, long quantity);
  bool sell(Market &m, string stock, long date, long quantity);
  string to_str();
};

#endif