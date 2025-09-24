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

    T rangeSum(int l, int r) const {
        if (r < l) {
            return 0;
        }
        return pre(r + 1) - pre(l);
    }
};