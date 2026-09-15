#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    vector<bool> visited(n, false);

    priority_queue<
        tuple<int, int, int>,
        vector<tuple<int, int, int>>,
        greater<tuple<int, int, int>>
    > pq;

    pq.push({0, 0, -1});

    int total = 0;

    cout << "MST Edges:\n";

    while (!pq.empty()) {
        auto [w, u, parent] = pq.top();
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = true;

        if (parent != -1) {
            cout << parent << " - " << u
                 << " : " << w << "\n";
            total += w;
        }

        for (auto [v, weight] : graph[u]) {
            if (!visited[v])
                pq.push({weight, v, u});
        }
    }

    cout << "Total Cost = " << total;

    return 0;
}
