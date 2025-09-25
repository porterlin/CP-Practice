// 由於本題 instructions[i] 最大只有 10^5，所以不用離散化也可以
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
        const int MOD = 1e9 + 7, m = 1e5 + 1;
        int cost = 0;
        FenwickTree<int> t(m);
        for (int i = 0; i < instructions.size(); i++) {
            int greaterCnt = i - t.pre(instructions[i] + 1), lessCnt = t.pre(instructions[i]);
            cost = (cost + min(lessCnt, greaterCnt)) % MOD;
            t.add(instructions[i]);
        }
        return cost;
    }
};