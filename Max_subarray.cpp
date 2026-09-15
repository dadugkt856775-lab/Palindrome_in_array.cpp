#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);

    for (auto &x : a)
        cin >> x;

    long long current = a[0];
    long long best = a[0];

    int start = 0;
    int bestStart = 0;
    int bestEnd = 0;

    for (int i = 1; i < n; i++) {

        if (a[i] > current + a[i]) {
            current = a[i];
            start = i;
        } else {
            current += a[i];
        }

        if (current > best) {
            best = current;
            bestStart = start;
            bestEnd = i;
        }
    }

    cout << "Maximum Sum = " << best << "\n";

    cout << "Subarray: ";

    for (int i = bestStart; i <= bestEnd; i++)
        cout << a[i] << " ";

    return 0;
}
