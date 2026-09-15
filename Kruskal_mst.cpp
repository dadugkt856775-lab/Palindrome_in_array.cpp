#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

class DSU {
    vector<int> parent, size;

public:
    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return false;

        if (size[a] < size[b])
            swap(a, b);

        parent[b] = a;
        size[a] += size[b];

        return true;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);

    for (auto &e : edges)
        cin >> e.u >> e.v >> e.w;

    sort(edges.begin(), edges.end(),
         [](const Edge& a, const Edge& b) {
             return a.w < b.w;
         });

    DSU dsu(n);

    int total = 0;
    int count = 0;

    cout << "MST Edges:\n";

    for (auto e : edges) {
        if (dsu.unite(e.u, e.v)) {
            cout << e.u << " - "
                 << e.v << " : "
                 << e.w << "\n";

            total += e.w;
            count++;
        }

        if (count == n - 1)
            break;
    }

    cout << "Minimum Cost = " << total;

    return 0;
}
