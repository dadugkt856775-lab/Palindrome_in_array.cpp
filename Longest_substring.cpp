#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    int n = a.size();
    int m = b.size();

    vector<vector<int>> dp(
        n + 1, vector<int>(m + 1, 0)
    );

    int longest = 0;
    string answer = "";

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;

                if (dp[i][j] > longest) {
                    longest = dp[i][j];

                    answer = a.substr(
                        i - longest,
                        longest
                    );
                }
            }
        }
    }

    cout << "Longest Common Substring = "
         << answer << "\n";

    cout << "Length = " << longest;

    return 0;
}
