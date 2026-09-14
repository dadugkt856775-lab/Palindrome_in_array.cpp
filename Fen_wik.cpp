#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
    vector<int> bit;
    int n;

public:
    FenwickTree(int n) {
        this->n = n;
        bit.resize(n + 1, 0);
    }

    void update(int index, int value) {
        for (index++; index <= n; index += index & -index)
            bit[index] += value;
    }

    int prefixSum(int index) {
        int sum = 0;

        for (index++; index > 0; index -= index & -index)
            sum += bit[index];

        return sum;
    }

    int rangeSum(int l, int r) {
        if (l == 0)
            return prefixSum(r);

        return prefixSum(r) - prefixSum(l - 1);
    }
};

int main() {
    int n;
    cin >> n;

    FenwickTree ft(n);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ft.update(i, x);
    }

    int q;
    cin >> q;

    while (q--) {
        int l, r;
        cin >> l >> r;

        cout << "Sum = "
             << ft.rangeSum(l, r) << "\n";
    }

    return 0;
}
