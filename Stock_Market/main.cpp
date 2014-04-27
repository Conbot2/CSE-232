#include "market.h"
#include "player.h"
#include <iostream>
using std::cout; using std::endl;
#include <algorithm>
using std::copy;
#include <iterator>
using std::ostream_iterator;
#include <sstream>
using std::ostringstream;
#include <iomanip>
using std::boolalpha; using std::fixed; using std::setprecision;
#include <cassert>

int next_date(int d){
  return d+1;
}

int main(){
  Market mark("dow.txt");
  // if you want to dump the stocks map, uncomment the code below
  // transform(mark.stocks.begin(), mark.stocks.end(), ostream_iterator<string>(cout, ", "),
  // 	    [](pair<long, vector<double>> p){
  // 	      ostringstream oss;
  // 	      oss << p.first;
  // 	      for(auto e : p.second)
  // 		oss << e << ", ";
  // 	      oss << "\n";
  // 	      return oss.str();
  // 	    }
  // 	    );

  cout << fixed << setprecision(2);
  cout << boolalpha;

  double price;
  price = mark.get_price("AA", 20120831);
  assert(price == 8.53); 
  price = mark.get_price("XOM", 20060927);
  assert(price == 58.82);
  price = mark.get_price("ZZZ", 20120801); // bad symbol
  assert(price == -1.0);
  price = mark.get_price("AA", 19990101); // bad date
  assert(price == -1.0);

  Player p1(1000);
  Player p2(1000);
  bool result;

  double delta = 0.05;
  result = p1.buy(mark, "IBM", 20120831, 5);
  assert(result == true);
  assert((p1.cash < (25.75 + delta)) && (p1.cash > (25.75 - delta)));
  assert(p1.stocks["IBM"] == 5);

  result = p1.sell(mark, "IBM", 20120831, 5);
  assert(result == true);
  assert((p1.cash < (1000 + delta)) && (p1.cash > (1000 - delta)));

  result = p2.buy(mark, "AA", 20010614, 25);
  assert(result == true);
  assert((p2.cash < (219 + delta)) && (p2.cash > (219 - delta)));
  assert(p2.stocks["AA"] == 25);

  // not enough cash
  result = p1.buy(mark, "AA", 20120831, 1000);
  assert(result == false);
  assert((p1.cash < (1000 + delta)) && (p1.cash > (1000 - delta)));

  // bad date
  result = p1.buy(mark, "AA", 21120831, 10);
  assert(result == false);
  assert(p1.cash == 1000);

  // don't have any of this
  result = p1.sell(mark, "AA", 20010614, 25);
  assert(result == false);
  assert((p1.cash < (1000 + delta)) && (p1.cash > (1000 - delta)));

  // don't have that much
  result = p2.sell(mark, "AA",  20010614, 50);
  assert(result == false);
  assert((p2.cash < (219 + delta)) && (p2.cash > (219 - delta)));

  p2.buy(mark, "XOM", 20010614, 1);
  cout << p2.to_str() << endl;

  cout << p1.to_str()<<endl;
    
}
