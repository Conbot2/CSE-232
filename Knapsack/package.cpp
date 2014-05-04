#include "package.h"

 Package::Package(long weight, long priority) {
    weight_ = weight;
    priority_ = priority;
 }

 Package::Package() {
    weight_ = 0;
    priority_ = 0;
 }

bool package_compare (const Package& lhs, const Package& rhs) {
    return (lhs.priority_ / lhs.weight_) > (rhs.priority_ / rhs.weight_);
 }

ostream &operator<<(ostream& out, Package p) {
    out << "Priority: " << p.priority_ << ", Weight: " << p.weight_;
    return out;
}