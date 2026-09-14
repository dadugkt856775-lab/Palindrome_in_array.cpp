#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);

    for (int &x : p)
        cin >> x;

    vector<vector<long long>> dp(n, vector<long long>(n, 0));

    for (int len = 2; len < n; len++) {
        for (int i = 1; i + len - 1 < n; i++) {
            int j = i + len - 1;

            dp[i][j] = LLONG_MAX;

            for (int k = i; k < j; k++) {
                long long cost =
                    dp[i][k] +
                    dp[k + 1][j] +
                    1LL * p[i - 1] * p[k] * p[j];

                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    cout << "Minimum Multiplications = "
         << dp[1][n - 1];

    return 0;
}
