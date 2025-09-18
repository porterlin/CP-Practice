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
    int n, m;
    cin >> n >> m;

    int ans = 0;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        int d = a[i] - a[i - 1], parity = b[i] ^ b[i - 1];
        if ((!parity && d % 2 == 1) || (parity && d % 2 == 0)) {
            ans--;
        }
        ans += d;
    }
    ans += m - a.back();

    cout << ans << "\n";
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