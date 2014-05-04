#include <iostream>
using std::cout; using std::endl;
#include <fstream>
using std::ifstream;
#include <vector>
using std::vector;
#include <algorithm>
using std::copy;
#include <iterator>
using std::ostream_iterator;
#include <string>
using std::string; using std::to_string;
#include <iomanip>
using std::boolalpha;
#include <cassert>
#include "package.h"
#include "knapsack.h"

int main(){
  ifstream inf("packages.txt");
  long weight;
  long priority;
  cout << boolalpha;
  vector<Package>vp;
  Package p(1,1);
  assert(p.weight_ == 1);
  assert(p.priority_ == 1);
  while(inf >> weight >> priority)
    vp.push_back(Package(weight, priority));
  // uncomment below to see the contents of the vector
  // transform(vp.begin(), vp.end(), ostream_iterator<string>(cout, "\n"),
  // 	    [](Package& p){return to_string(p.weight_);}
  // 	    );
  // cout << endl;
  Knapsack ks(100);
  assert(ks.empty() == 1);
  cout << ks.empty() <<endl;
  ks.add(Package(10,100));
  assert(ks.empty() == 0);
  assert(ks.weight() == 10);
  assert(ks.priority() == 100);
  cout << ks << endl;
  cout << "Weight:"<<ks.weight() << endl;
  cout << "Priority:"<<ks.priority() << endl;

  solve_KS(vp, ks);
  assert(ks.weight() == 56);
  assert(ks.priority() == 119);
  cout << ks << endl;
  cout << "Weight:"<<ks.weight() << endl;
  cout << "Priority:"<<ks.priority() << endl;
}
		 
