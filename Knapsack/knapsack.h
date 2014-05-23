#include "package.h"
#include <vector>
using std::vector;

#ifndef __KNAPSACK_H_INCLUDED__
#define __KNAPSACK_H_INCLUDED__

class Knapsack
{
    private:
        Package* data_;
        long weight_limit_, capacity_, size_;
    public:
        Knapsack(long max);
        long find_weight();
        bool add(Package p);
        bool empty();
        long weight();
        long priority();
        bool compare (Package, Package);
        friend ostream &operator<<(ostream &out, const Knapsack &ks);
        friend void solve_KS(vector<Package>& vp, Knapsack& k);
};

#endif