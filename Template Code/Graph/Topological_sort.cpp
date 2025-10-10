vector<vector<int>> adjList;
vector<int> topoLogicalSort(vector<pair<int, int>> edges, int nodeCount) {
    vector<int> inDegree(nodeCount + 1, 0);
    vector<vector<int>> adjList(nodeCount + 1);
    for(auto edge : edges) {
        inDegree[edge.second] += 1;
        adjList[edge.first].push_back(edge.second);
    }
    queue<int> nodesWithIndegreeZero; 
    for(int i = 0; i <nodeCount; i++) {
        if(inDegree[i] == 0) {
            nodesWithIndegreeZero.push(i);
        }
    }
    vector<int> topoLogicallySortedNodes;
    while (!nodesWithIndegreeZero.empty()) {
        int node = nodesWithIndegreeZero.front();
        topoLogicallySortedNodes.push_back(node);
        nodesWithIndegreeZero.pop();
        for (auto x: adjList[node]) {
            inDegree[x]--;
            if (inDegree[x] == 0) {
                nodesWithIndegreeZero.push(x);
            }
        }
    }
    return topoLogicallySortedNodes;
}