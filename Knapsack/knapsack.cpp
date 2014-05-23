#include "knapsack.h"
#include <algorithm>
using std::sort;

Knapsack::Knapsack(long max) {
    capacity_ = 10;
    size_ = 0;
    weight_limit_ = max;
    data_ = new Package[capacity_];
}

bool Knapsack::add(Package p) {
    if (this->weight() + p.weight_ > weight_limit_)
        return false;
    else if (this->weight() + p.weight_ <= weight_limit_ && size_ >= capacity_) {
        Package* new_data = new Package[size_ * 2];
        // copy
        for (long i = 0; i < size_; i++)
            new_data[i] = data_[i];
        // swap
        delete [] data_;
        data_ = new_data;
        delete new_data;
        // add
        data_[size_] = p;
        ++size_;
        return true;
    }
    else if (this->weight() + p.weight_ <= weight_limit_ && size_ < capacity_) {
        data_[size_] = p;
        ++size_;
        return true;
    }
}

bool Knapsack::empty() {
    return size_ == 0;
}

long Knapsack::weight() {
    long total_weight = 0;
    if (size_ != 0) {
        for (long i = 0; i <= size_; ++i)
            total_weight += data_[i].weight_;
    }
    return total_weight;
}

long Knapsack::priority() {
    long total_priority = 0;
    if (size_ != 0) {
        for (long i = 0; i <= size_; ++i)
            total_priority += data_[i].priority_;
    }
    return total_priority;
}

ostream &operator<<(ostream &out, const Knapsack &ks) {
    for (long i = 0; i < ks.size_; i++)
        out << ks.data_[i] << '\n';
    return out;
}

bool compare(Package p, Package q) {
    return package_compare(p,q);
}

void solve_KS(vector<Package>& vp, Knapsack& k) {
    for (long i = 0; i < k.size_; i++)
        vp.push_back(k.data_[i]);
    sort(vp.begin(),vp.end(),compare);
    k = Knapsack(k.weight_limit_);
    for (auto elem : vp)
        k.add(elem);
}