#include <vector>
#include <numeric>

using namespace std;

class Solution {
private:
    vector<int> parent;

    // Find operation with Path Compression
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0); // parent[i] = i

        int components = n;

        for (const auto& edge : edges) {
            int rootU = find(edge[0]);
            int rootV = find(edge[1]);

            // If they belong to different components, merge them
            if (rootU != rootV) {
                parent[rootU] = rootV;
                components--; // Reduce component count
            }
        }

        return components;
    }
};