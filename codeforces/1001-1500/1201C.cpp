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
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ranges::sort(a);

    i64 l = a[n / 2], r = a[n - 1] + k;
    while (l <= r) {
        i64 mid = r - (r - l) / 2;

        i64 diff = 0;
        for (i64 i = n / 2; i < n; i++) {
            if (a[i] >= mid) {
                break;
            }
            diff += mid - a[i];
        }

        if (diff <= k) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << r << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}