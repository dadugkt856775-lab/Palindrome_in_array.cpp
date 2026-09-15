#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n <= 1) {
        cout << 1;
        return 0;
    }

    long long first = 1;
    long long second = 1;

    for (int i = 2; i <= n; i++) {
        long long current = first + second;
        first = second;
        second = current;
    }

    cout << "Number of Ways = " << second;

    return 0;
}
