// 離散化版本
template<typename T>
class FenwickTree {
    vector<T> tree;

public:
    FenwickTree(int n): tree(n + 1) {}

    void add(int x) {
        for (int i = x + 1; i < tree.size(); i += i & -i) {
            tree[i]++;
        }
    }

    T pre(int i) const {
        T res = 0;
        while (i > 0) {
            res += tree[i];
            i -= i & -i;
        }
        return res;
    }
};

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        const int MOD = 1e9 + 7;
        auto sorted = instructions;
        ranges::sort(sorted);
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        int m = sorted.size();

        int cost = 0;
        FenwickTree<int> t(m);
        for (int i = 0; i < instructions.size(); i++) {
            int idx = ranges::lower_bound(sorted, instructions[i]) - sorted.begin();
            int greaterCnt = i - t.pre(idx + 1), lessCnt = t.pre(idx);
            cost = (cost + min(lessCnt, greaterCnt)) % MOD;
            t.add(idx);
        }
        return cost;
    }
};