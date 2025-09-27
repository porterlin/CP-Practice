template<typename T>
class FenwickTree {
    vector<T> tree;

public:
    FenwickTree(int n): tree(n + 1) {}

    void add(int x, T val) {
        for (int i = x + 1; i < tree.size(); i += i & -i) {
            tree[i] += val;
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
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> ans(queries.size());
        unordered_map<int, int> mp;
        FenwickTree<int> t(queries.size() + m);
        for (int i = 1; i <= m; i++) {
            t.add(queries.size() + i, 1);
            mp[i] = queries.size() + i;
        }

        int insertIdx = queries.size() - 1;
        for (int i = 0; i < queries.size(); i++) {
            int q = queries[i];
            ans[i] = t.pre(mp[q]);
            t.add(mp[q], -1);
            t.add(insertIdx, 1);
            mp[q] = insertIdx;
            insertIdx--;
        }
        return ans;
    }
};