#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);

    for (auto &e : edges)
        cin >> e.u >> e.v >> e.w;

    int source, destination;
    cin >> source >> destination;

    const int INF = 1e9;
    vector<int> dist(n, INF);
    vector<int> parent(n, -1);

    dist[source] = 0;

    for (int i = 1; i < n; i++) {
        bool changed = false;

        for (auto e : edges) {
            if (dist[e.u] != INF &&
                dist[e.u] + e.w < dist[e.v]) {

                dist[e.v] = dist[e.u] + e.w;
                parent[e.v] = e.u;
                changed = true;
            }
        }

        if (!changed)
            break;
    }

    if (dist[destination] == INF) {
        cout << "No Path";
        return 0;
    }

    vector<int> path;

    for (int v = destination; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());

    cout << "Shortest Distance = " << dist[destination] << "\n";
    cout << "Path: ";

    for (int v : path)
        cout << v << " ";

    return 0;
}
