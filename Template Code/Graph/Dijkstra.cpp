// Dijkstra dosen't works on negative weighted cycle

// n = node_count
// par[u] = parent of node u.
// cnt[u] = number of shortest path from node s;
// s = starting node of dijkstra
// t = ending node of dijkstra
// Graph adjacency list (1-based indexing)
vector<vector<pair<int, int>>> g; // g[u] = vector of (v, w)

// pair.first = node, pair.second = cost;
vector<ll> dijkstra(int s, int t, vector<int> &cnt, vector<int> &par, int n) {
    const ll inf = 1e18;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    vector<ll> d(n + 1, inf);
    vector<bool> vis(n + 1, 0);
    q.push({0, s});
    d[s] = 0;
    cnt.assign(n + 1, 0);
    par.assign(n + 1, -1);
    cnt[s] = 1;

    while (!q.empty()) {
        auto [du, u] = q.top();
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;

        for (auto [v, w] : g[u]) {
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                q.push({d[v], v});
                par[v] = u;
                cnt[v] = cnt[u];
            } else if (d[u] + w == d[v]) {
                cnt[v] += cnt[u]; // number of shortest paths, use mod if needed
            }
        }
    }
    return d;
}

// Reconstruct path from s to t using parent array
vector<int> find_shortest_path(int s, int t, const vector<int> &par) {
    vector<int> path;
    for (int cur = t; cur != -1; cur = par[cur])
        path.push_back(cur);
    reverse(path.begin(), path.end());
    if (path.empty() || path.front() != s)
        path.clear(); // unreachable
    return path;
}