#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;

    void build(vector<int>& a, int node, int l, int r) {
        if (l == r) {
            tree[node] = a[l];
            return;
        }

        int mid = (l + r) / 2;

        build(a, node * 2, l, mid);
        build(a, node * 2 + 1, mid + 1, r);

        tree[node] = tree[node * 2]
                   + tree[node * 2 + 1];
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql)
            return 0;

        if (ql <= l && r <= qr)
            return tree[node];

        int mid = (l + r) / 2;

        return query(node * 2, l, mid, ql, qr)
             + query(node * 2 + 1, mid + 1, r, ql, qr);
    }

public:
    SegmentTree(vector<int>& a) {
        n = a.size();
        tree.resize(4 * n);
        build(a, 1, 0, n - 1);
    }

    int rangeSum(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int &x : a)
        cin >> x;

    SegmentTree st(a);

    int q;
    cin >> q;

    while (q--) {
        int l, r;
        cin >> l >> r;

        cout << st.rangeSum(l, r) << "\n";
    }

    return 0;
}
