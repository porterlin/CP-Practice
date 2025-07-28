class Graph {
    vector<vector<pair<int, int>>> graph;
    int nn;
public:
    Graph(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        for (auto& e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
        }
        nn = n;
    }
    
    void addEdge(vector<int> edge) {
        graph[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        vector<long long> dis(nn, LLONG_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        dis[node1] = 0;
        pq.push({0, node1});
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (u == node2) {
                return d;
            }
            if (d > dis[u]) {
                continue;
            }
            for (auto& [v, w] : graph[u]) {
                if (d + w < dis[v]) {
                    dis[v] = d + w;
                    pq.push({dis[v], v});
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */