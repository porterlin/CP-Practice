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

constexpr int MOD = 998244353;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    i64 cnt = 2;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] <= a[i + 1] && a[i] <= b[i + 1] && b[i] <= a[i + 1] && b[i] <= b[i + 1]) {
            cnt = (cnt * 2) % MOD;
        }
    }

    cout << cnt << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}