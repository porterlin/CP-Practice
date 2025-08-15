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

    int moves = 0, aa = 0, bb = 0, preA = 0, preB = 0;
    int l = 0, r = n - 1;
    while (l <= r) {
        moves++;
        int cur = 0;
        if (preA <= preB) {
            while (cur <= preB && l <= r) {
                cur += a[l++];
            }
            aa += cur;
            preA = cur;
        } else {
            while (cur <= preA && l <= r) {
                cur += a[r--];
            }
            bb += cur;
            preB = cur;
        }
    }

    cout << moves << " " << aa << " " << bb << "\n";
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