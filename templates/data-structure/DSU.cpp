class DSU {
public:
	vector<int> parent;
	vector<int> size;
	int cc;

	DSU(int n): parent(n), size(n, 1), cc(n) {
		iota(parent.begin(), parent.end(), 0);
	}

	int find(int x) {
		if (parent[x] == x)
			return x;
		return parent[x] = find(parent[x]);
	}

	bool is_same(int x, int y) {
		return find(x) == find(y);
	}

	bool merge(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y)
			return false;
		parent[x] = y;
		size[y] += size[x];
		size[x] = size[y];
		cc--;
		return true;
	}
};