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
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        ranges::sort(rectangles);
        vector<int> x;
        for (auto& r : rectangles) {
            if (x.empty() || r[0] > x.back()) {
                x.push_back(r[0]);
            }
        }

        vector<FenwickTree<int>> y(101, FenwickTree<int>(x.size()));
        for (auto& r : rectangles) {
            int idx = ranges::lower_bound(x, r[0]) - x.begin();
            y[r[1]].add(idx, 1);
        }

        vector<int> ans(points.size());
        for (int i = 0; i < points.size(); i++) {
            int cnt = 0;
            for (int j = 0; j < points[i][1]; j++) {
                cnt += y[j].pre(x.size());
            }
            for (int j = points[i][1]; j < 101; j++) {
                int idx = ranges::lower_bound(x, points[i][0]) - x.begin();
                cnt += y[j].pre(idx);
            }
            ans[i] = rectangles.size() - cnt;
        }
        return ans;
    }
};