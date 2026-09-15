#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long g, l;
    cin >> g;

    l = g;

    for (int i = 1; i < n; i++) {
        long long x;
        cin >> x;

        g = gcd(g, x);
        l = l / gcd(l, x) * x;
    }

    cout << "GCD = " << g << "\n";
    cout << "LCM = " << l;

    return 0;
}
