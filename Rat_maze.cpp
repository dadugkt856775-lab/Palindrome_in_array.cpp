#include <bits/stdc++.h>
using namespace std;

int n;

bool solve(vector<vector<int>>& maze,
           vector<vector<int>>& path,
           int r, int c) {

    if (r == n - 1 && c == n - 1) {
        path[r][c] = 1;
        return true;
    }

    if (r < 0 || c < 0 || r >= n || c >= n ||
        maze[r][c] == 0 || path[r][c] == 1)
        return false;

    path[r][c] = 1;

    if (solve(maze, path, r + 1, c) ||
        solve(maze, path, r, c + 1) ||
        solve(maze, path, r - 1, c) ||
        solve(maze, path, r, c - 1))
        return true;

    path[r][c] = 0;

    return false;
}

int main() {
    cin >> n;

    vector<vector<int>> maze(n, vector<int>(n));
    vector<vector<int>> path(n, vector<int>(n, 0));

    for (auto& row : maze)
        for (int& x : row)
            cin >> x;

    if (solve(maze, path, 0, 0)) {
        cout << "Path Found:\n";

        for (auto& row : path) {
            for (int x : row)
                cout << x << " ";
            cout << "\n";
        }
    } else {
        cout << "No Path";
    }

    return 0;
}
