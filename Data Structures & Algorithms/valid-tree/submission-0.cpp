class Solution {
public:

    void dfs (int node, vector<vector<int>>& graph, vector<bool>& visited)
    {
        visited[node] = true;

        for (int neighbour : graph[node])
        {
            if (!visited[neighbour])
                dfs(neighbour, graph, visited);
        }
    }

    bool validTree(int n, vector<vector<int>>& edges) {

        if(edges.size() != n-1)
            return false;

        vector<vector<int>> graph(n);

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> visited(n, false);

        dfs(0, graph, visited);

        for (bool node : visited)
        {
            if (node == false)
                return false;
        }

        return true;
    }
};
