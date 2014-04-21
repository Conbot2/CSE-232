#include <cmath>
#include <iostream>
using std::cin; using std::cout; using std::endl;
using std::exit;

int prompt() {
    int num = 1;
    cout << "Enter an even integer greater than two: ";
    cin >> num;
    while ((num <= 2) || (num % 2 != 0)) {
        cout << "Invalid input. Try again: ";
        cin >> num;
    }
    return num;
}

bool is_prime(int num) {
    bool prime = true;
    int test = 2;
    while (test <= sqrt(num)) {
        if (num % test == 0) {
            prime = false;
            break;
        }
        ++test;
    }
    return prime;
}

int find_second(int input, int start) {
    // find second number for addition
    for (int i = start; i < input; ++i) {
        if (is_prime(i))
            return i;
    }
}

int main() {
    const int input = prompt();
    int num2;
    for (int num1 = 2; num1 < input; ++num1) {
        int start = 2;
        if (!is_prime(num1))
            continue;
        else if (is_prime(num1)) {
            do {
                num2 = find_second(input,start);
                if (num1 + num2 == input) {
                    cout << input << " is the sum of the primes: " << num1 << ',' << num2 << endl;
                    exit(0);
                }
                else
                    ++start;
            } while (start < input);
        }
    }
    return 0;
}