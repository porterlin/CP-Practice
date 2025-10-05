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

    unordered_set<int> st;
    vector<int> start;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) {
            st.insert(i);
            start.push_back(i);
            continue;
        }
        g[a].push_back(i);
        g[b].push_back(i);
    }
    
    vector<int> vis(n + 1);
    auto dfs = [&](auto&& dfs, int node) -> void {
        vis[node] = 1;
        st.insert(node);
        for (auto& next : g[node]) {
            if (!vis[next]) {
                dfs(dfs, next);
            }
        }
    };

    for (int i = 0; i < start.size(); i++) {
        if (!vis[start[i]]) {
            dfs(dfs, start[i]);
        }
    }

    cout << st.size() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}