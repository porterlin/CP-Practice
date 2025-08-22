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

    int x1 = INT_MIN, x2 = INT_MAX, y1 = INT_MIN, y2 = INT_MAX;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        // change manhattan distance to chebyshev distance
        int x_chebyshev = x + y;
        int y_chebyshev = x - y;

        x1 = max(x1, x_chebyshev);
        x2 = min(x2, x_chebyshev);
        y1 = max(y1, y_chebyshev);
        y2 = min(y2, y_chebyshev);
    }

    cout << max(x1 - x2, y1 - y2) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}