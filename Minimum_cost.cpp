#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> points(n);

    for (auto &[x, y] : points)
        cin >> x >> y;

    vector<int> dist(n, INT_MAX);
    vector<bool> used(n, false);

    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    dist[0] = 0;
    pq.push({0, 0});

    int total = 0;

    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();

        if (used[u])
            continue;

        used[u] = true;
        total += cost;

        for (int v = 0; v < n; v++) {
            if (!used[v]) {
                int d = abs(points[u].first - points[v].first)
                      + abs(points[u].second - points[v].second);

                if (d < dist[v]) {
                    dist[v] = d;
                    pq.push({d, v});
                }
            }
        }
    }

    cout << "Minimum Cost = " << total;

    return 0;
}
