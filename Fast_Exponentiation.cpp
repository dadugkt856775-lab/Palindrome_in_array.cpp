#include <bits/stdc++.h>
using namespace std;

long long power(long long base, long long exponent) {
    long long result = 1;

    while (exponent > 0) {

        if (exponent % 2 == 1)
            result *= base;

        base *= base;
        exponent /= 2;
    }

    return result;
}

int main() {
    long long base, exponent;
    cin >> base >> exponent;

    cout << "Answer = "
         << power(base, exponent);

    return 0;
}
