#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
    string s;
    cin >> s;

    int ch[26]{};
    for (int i = 0; i < s.size(); i++) {
        ch[s[i] - 'a']++;
    }

    int cntOdd = 0;
    for (int i = 0; i < 26; i++) {
        if (ch[i] % 2 == 1) {
            cntOdd++;
        }
    }

    if (cntOdd == 0 || (cntOdd % 2 == 1)) {
        cout << "First\n";
    } else {
        cout << "Second\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}