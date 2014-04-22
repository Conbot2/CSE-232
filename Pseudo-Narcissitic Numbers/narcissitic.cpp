#include <cmath>
#include <iostream>
using std::cout; using std::cin; using std::endl;
using std::exit;

void prompt(int& one, int& two, int& exponent) {
    cout << "Enter three space-separated values (first, second, power) or 0 to quit" << endl;
    cin >> one >> two >> exponent;
    if ((one <= 0) || (two <= 0) || (exponent <= 0)) {
        cout << "Exiting..." << endl;
        exit(0);
    }
}

void order_parameters(int& first, int& second) {
    if (first > second) {
        int temp;
        temp = first;
        first = second;
        second = temp;
    }
}

bool narc_num(int num, int power) {
// Checks if given number is narcissistic
    int digit;
    int temp = num;
    int digit_sum = 0;
    while (temp > 0) {
        digit = temp % 10;
        temp /= 10;
        digit_sum += pow(digit,power);
    }
    if (digit_sum == num)
        return true;
    else
        return false;
}

int check_range(int first, int last, int power) {
// Checks range for narcissistic numbers
    order_parameters(first,last);
    bool narcissistic;
    int count = 0;
    for (int i = first; i <= last; ++i) {
        narcissistic = narc_num(i,power);
        if (narcissistic == true) {
            cout << i << " is a narcissistic number of order: " << power << endl;
            ++count;
        }
    }
    return count;
}

int main() {
    int first = 1;
    int second = 2;
    int power = 1;
    int nn_count;

    while (true) {
        prompt(first,second,power);
        nn_count = check_range(first,second,power);
        cout << "Saw " << nn_count << " narcissistic numbers of order " << power
        << " in range " << first << " to " << second << endl;
    }
    return 0;
}