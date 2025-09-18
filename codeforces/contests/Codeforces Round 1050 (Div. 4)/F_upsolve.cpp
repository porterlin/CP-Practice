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

    int max_k = 0;
    vector<vector<int>> vec(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        max_k = max(max_k, k);
        vec[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> vec[i][j];
        }
    }

    ranges::sort(vec, [](auto a, auto b) {
        return a.size() < b.size();
    });

    vector<int> ans(max_k, INT_MAX), edit;
    edit.push_back(0);
    for (auto& v : vec) {
        for (int e = 0; e < edit.size(); e++) {
            int l = edit[e], r = (e + 1 < edit.size() ? edit[e + 1] : v.size());
            bool replace = false;
            for (int i = l; i < r; i++) {
                if (v[i] > ans[i]) {
                    break;
                }
                if (v[i] < ans[i]) {
                    replace = true;
                    break;
                }
            }
            if (replace) {
                for (int i = l; i < v.size(); i++) {
                    ans[i] = v[i];
                }
                while (edit.back() > l) {
                    edit.pop_back();
                }
                edit.push_back(v.size());
                break;
            }
        }
    }

    for (int i = 0; i < max_k; i++) {
        cout << ans[i] << " \n"[i == max_k - 1];
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