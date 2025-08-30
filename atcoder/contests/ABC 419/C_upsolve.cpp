#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
    int n;
    cin >> n;

    int x1 = 0, x2 = INT_MAX, y1 = 0, y2 = INT_MAX;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        x1 = max(x1, x);
        x2 = min(x2, x);
        y1 = max(y1, y);
        y2 = min(y2, y);
    }

    cout << (max(x1 - x2, y1 - y2) + 1) / 2 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}