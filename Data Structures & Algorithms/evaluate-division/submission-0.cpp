#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // Step 1: Build the directed graph
        unordered_map<string, vector<pair<string, double>>> adj;

        for (int i = 0; i < equations.size(); i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];

            adj[u].push_back({v, val});
            adj[v].push_back({u, 1.0 / val});
        }

        // Step 2: Evaluate each query using DFS
        vector<double> results;

        for (const auto& query : queries) {
            string start = query[0];
            string target = query[1];

            // Case 1: Either node doesn't exist in the graph
            if (adj.find(start) == adj.end() || adj.find(target) == adj.end()) {
                results.push_back(-1.0);
            } 
            // Case 2: Querying the same node that exists
            else if (start == target) {
                results.push_back(1.0);
            } 
            // Case 3: Search for path from start to target
            else {
                unordered_set<string> visited;
                double res = dfs(start, target, adj, visited);
                results.push_back(res);
            }
        }

        return results;
    }

private:
    double dfs(const string& current, const string& target,
               unordered_map<string, vector<pair<string, double>>>& adj,
               unordered_set<string>& visited) {
        
        // Base case: Target reached
        if (current == target) {
            return 1.0;
        }

        visited.insert(current);

        // Explore all connected variables
        for (const auto& neighbor : adj[current]) {
            string nextNode = neighbor.first;
            double weight = neighbor.second;

            if (visited.find(nextNode) == visited.end()) {
                double product = dfs(nextNode, target, adj, visited);
                
                // If a valid path to target was found
                if (product != -1.0) {
                    return weight * product;
                }
            }
        }

        return -1.0; // Path not found
    }
};