#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> seg(n);
    seg[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] == a[i + 1]) {
            seg[i] = seg[i + 1];
        } else {
            seg[i] = i;
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;

        if (seg[l] == seg[r] || seg[l] + 1 > r) {
            cout << -1 << " " << -1 << "\n";
        } else {
            cout << seg[l] + 1 << " " << seg[l] + 2 << "\n";
        }
    }
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