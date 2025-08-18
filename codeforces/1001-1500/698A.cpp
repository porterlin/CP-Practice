#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> dp(n, vector<int>(3));
    if (a[0] == 1) {
        dp[0][1]++;
    } else if (a[0] == 2) {
        dp[0][2]++;
    } else if (a[0] == 3) {
        dp[0][1]++;
        dp[0][2]++;
        dp[0][0]++;
    }

    for (int i = 1; i < n; i++) {
        dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
        if (a[i] == 1 || a[i] == 3) {
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + 1;
        }
        if (a[i] == 2 || a[i] == 3) {
            dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
        }
    }

    cout << n - ranges::max(dp[n - 1]) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}