#include <iostream>
using std::cout; using std::cin; using std::endl;
#include <string>
using std::string; using std::to_string; using std::stol;

long rev_num(long n) {
    // reverse digits of n
    string reverse;
    string n_str = to_string(n);
    for (long i = n_str.length() - 1; i >= 0; i--)
        reverse += n_str[i];
    long n_rev = stol(reverse);
    return n_rev;
}

bool is_palindrome(long n) {
    bool palindrome;
    long reverse = rev_num(n);
    if (reverse == n)
        palindrome = true;
    else
        palindrome = false;
    return palindrome;
}

void order_parameters(long &first, long &second) {
    if (first > second) {
        int temp;
        temp = first;
        first = second;
        second = temp;
    }
}

bool check_lychrel(long n, long limit) {
    // applies 196 algorithm until number becomes a palindrome or breaks limit
    long start = n;
    bool lychrel = true;
    long n_rev;
    for (long i = 1; i <= limit; ++i) {
        if (is_palindrome(n)) {
            lychrel = false;
            break;
        }
        else {
            n_rev = rev_num(n);
            n += n_rev;
        }
    }
    return lychrel;
}

long check_range(long start, long end, long limit, long &natural_cnt, long &pal_cnt) {
    // finds potential lychrel numbers in range
    bool is_lychrel;
    long lychrel_cnt;
    order_parameters(start,end);
    for (long t = start; t <= end; ++t) {
        is_lychrel = check_lychrel(t,limit);
        if (is_lychrel) {
            cout << "Found lychrel number: " << t << endl;
            ++lychrel_cnt;
        }
        else if ((!is_lychrel) && (is_palindrome(t)))
            ++natural_cnt;
        else
            ++pal_cnt;
    }
    return lychrel_cnt;
}

int main() {
    long start, finish, limit;
    long natural_cnt = 0;
    long pal_cnt = 0;
    long lychrel_count = 0;

    do {
        cout << "Provide first, last, and limit (all greater than one)" << endl;
        cin >> start >> finish >> limit;
    } while ((start < 1) || (finish < 1) || (limit < 1));
    lychrel_count = check_range(start, finish, limit, natural_cnt, pal_cnt);
    cout << "Summary for range " << start << ", " << finish << " with limit " <<
    limit << ":" << endl;
    cout << "lychrel count: " << lychrel_count << ", natural count: " <<
    natural_cnt << ", palindrome count: " << pal_cnt << endl;
    return 0;
}