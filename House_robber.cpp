#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> money(n);

    for (int &x : money)
        cin >> x;

    if (n == 0) {
        cout << 0;
        return 0;
    }

    if (n == 1) {
        cout << money[0];
        return 0;
    }

    vector<int> dp(n);

    dp[0] = money[0];
    dp[1] = max(money[0], money[1]);

    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 1],
                    dp[i - 2] + money[i]);
    }

    cout << "Maximum Money = " << dp[n - 1];

    return 0;
}
