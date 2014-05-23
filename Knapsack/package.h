#include <ostream>
using std::ostream;

#ifndef __PACKAGE_H_INCLUDED__
#define __PACKAGE_H_INCLUDED__

struct Package
{
    long weight_;
    long priority_;
    Package();
    Package(long weight, long priority);
    friend ostream &operator<<(ostream&, Package p);
    friend bool package_compare (const Package& lhs, const Package& rhs);
};

#endif