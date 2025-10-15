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

constexpr i64 INF = 1e18;

void solve() {
    int n;
    cin >> n;

    i64 f = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        f += i % 2 ? -a[i] : a[i];
    }

    if (n == 1) {
        cout << a[0] << "\n";
        return;
    }

    i64 delta = n % 2 ? n - 1 : n - 2;
    i64 odd_mx = -INF, even_mx = -INF;
    for (int i = 0; i < n; i++) {
        if (i % 2) {
            delta = max(delta, even_mx + 2 * a[i] + i);
            odd_mx = max(odd_mx, i64(2 * a[i] - i));
        } else {
            delta = max(delta, odd_mx - (2 * a[i] - i));
            even_mx = max(even_mx, i64(-2 * a[i] - i));
        }
    }

    cout << f + delta << "\n";
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