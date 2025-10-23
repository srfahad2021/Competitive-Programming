vector<vector<int>> dis;

// n = node_count
// edge[i] = {u, {v, w}};
void floyed_warshall(int n, vector<pair<int, pair<int, int>>> &edge){ 
    dis.assign(n + 1, vector<int>(n + 1, 1e18));
    for(int i = 1; i <= n; i++) dis[i][i] = 0;
    for(int i = 0; i < edge.size(); i++){
        int u = edge[i].first;
        int v = edge[i].second.first;
        int w = edge[i].second.second;
        dis[u][v] = min(dis[u][v], w);
        dis[v][u] = min(dis[v][u], w); // if directed, comment
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]); 
            }
        }
    }
}