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
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> ans;
    map<int, int> mp;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        mp[a]++;
        if (mp[a] == m) {
            ans.push_back(a);
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}