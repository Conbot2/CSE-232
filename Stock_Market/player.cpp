#include "player.h"
using std::to_string;

Player::Player(double amount) {
    cash = amount;
}

bool Player::buy(Market &m, string stock, long date, long quantity) {
  bool valid;
  double price = m.get_price(stock,date) * quantity;
  if (price <= cash && price > -1.0)
    valid = true;
  else
    valid = false;

  if (valid) {
    cash -= price;
    stocks[stock] += quantity;
  }
  return valid;
}

bool Player::sell(Market &m, string stock, long date, long quantity) {
  bool has_stock, has_enough;
  if (stocks[stock] > 0)
    has_stock = true;
  else
    has_stock = false;

  if (stocks[stock] >= quantity)
    has_enough = true;
  else
    has_enough = false;

  if (has_stock && has_enough) {
    double profit = m.get_price(stock,date) * quantity;
    cash += profit;
    stocks[stock] -= quantity;
  }
  return (has_stock && has_enough);
}

string Player::to_str() {
  string output = "Player has:" + to_string(cash) + " dollars, stocks are:\n";
  string line;
  for (auto elem : stocks) {
    line = elem.first + ", quantity " + to_string(elem.second) + "\n";
    output += line;
  }
  return output;
}