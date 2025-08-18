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

    vector<array<int, 2>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1];
    }

    ranges::sort(v);

    int last = 0;
    for (int i = 0; i < n; i++) {
        if (v[i][1] >= last) {
            last = v[i][1];
        } else if (v[i][0] >= last) {
            last = v[i][0];
        }
    }

    cout << last << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}