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
    string a, b, c;
    cin >> n >> a >> m >> b >> c;

    deque<char> dq;
    for (int i = 0; i < n; i++) {
        dq.push_back(a[i]);
    }

    for (int i = 0; i < m; i++) {
        if (c[i] == 'V') {
            dq.push_front(b[i]);
        } else {
            dq.push_back(b[i]);
        }
    }

    for (int i = 0; i < dq.size(); i++) {
        cout << dq[i];
    }
    cout << "\n";
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