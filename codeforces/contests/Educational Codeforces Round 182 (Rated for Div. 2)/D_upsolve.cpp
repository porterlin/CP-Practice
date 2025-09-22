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
    int n, y;
    cin >> n >> y;

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    int m = ranges::max(c) + 1;

    vector<int> pre(m);
    for (int i = 0; i < n; i++) {
        pre[c[i]]++;
    }

    // 前綴和用於快速統計有多少個原始價格在某個區間中
    for (int i = 1; i < m; i++) {
        pre[i] += pre[i - 1];
    }

    i64 ans = -1e18;
    for (int x = 2; x <= m; x++) { // 枚舉 x
        i64 cur = 0;
        for (int v = 1; (v - 1) * x < m; v++) { // 枚舉新價格 v
            int cnt = pre[min(m - 1, v * x)] - pre[(v - 1) * x]; // 計算有多少個數折扣後會等於新價格 v
            cur += 1LL * v * cnt; // 計算新價格為 v 時的價值
            cur -= 1LL * y * (cnt - min(cnt, pre[v] - pre[v - 1]));
            /*
            pre[v] - pre[v - 1] 計算原始價格中有多少個數等於 v，依照題意這些數可以不用貼標籤
            如果原始的 v 的數量大於折扣後 v 的數量，那就表示全部都可以由原標籤去貼，所以要跟 cnt 取 min
            */
        }
        ans = max(ans, cur);
    }

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