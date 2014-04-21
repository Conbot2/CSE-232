#include <cmath>
#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
  double debt;
  int bill, population;
  
  cout << "What is the US national debt (in dollars)? ";
  cin >> debt;
  cout << "Use what bill denomination? ";
  cin >> bill;
  cout << "What is the current US population? ";
  cin >> population;
  
  const double thickness = 6.7866162E-8;
  double needed = debt / bill;
  double height = needed * thickness;
  cout << "\nHeight of the US debt in $" << bill << " bills: " << height
  << " miles." << endl;
          
  const int moon_dist = 238857;
  double factor = height / moon_dist;
  cout << "That's " << factor << " times the distance to the moon!" << endl;
  
  double owed = debt / population;
  int rounded = round(owed);
  cout << "That's $" << rounded << " per person!" << endl;
  
  return 0;
}
