class Solution {
private: 
    vector<int> parent;

    int findLeader (int node) {

        if (parent[node] == node) {
            return node;
        }

        return parent[node] = findLeader(parent[node]);
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();

        parent.resize(n + 1);
        for (int i=1; i <= n; i++) {
            parent[i] = i;
        }

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            int leaderU = findLeader(u);
            int leaderV = findLeader(v);

            if (leaderU == leaderV) {
                return edge;
            }

            parent[leaderU] = leaderV;
        }

        return {};
    }
};
