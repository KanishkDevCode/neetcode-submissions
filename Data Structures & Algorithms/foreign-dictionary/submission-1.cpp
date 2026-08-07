#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>

class Solution {
public:
    std::string foreignDictionary(std::vector<std::string>& words) {
        std::unordered_map<char, std::unordered_set<char>> adj;
        std::unordered_map<char, int> inDegree;

        // Step 1: Collect all unique characters
        for (const std::string& word : words) {
            for (char c : word) {
                inDegree[c] = 0;
            }
        }

        // Step 2: Build the adjacency list and in-degrees
        for (size_t i = 0; i < words.size() - 1; ++i) {
            const std::string& w1 = words[i];
            const std::string& w2 = words[i + 1];

            // Invalid prefix check (e.g., ["abc", "ab"])
            if (w1.size() > w2.size() && w1.substr(0, w2.size()) == w2) {
                return "";
            }

            size_t minLen = std::min(w1.size(), w2.size());
            for (size_t j = 0; j < minLen; ++j) {
                if (w1[j] != w2[j]) {
                    char u = w1[j];
                    char v = w2[j];

                    if (!adj[u].count(v)) {
                        adj[u].insert(v);
                        inDegree[v]++;
                    }
                    break; // Only the first differing character matters
                }
            }
        }

        // Step 3: Topological Sort using Kahn's Algorithm (BFS)
        std::queue<char> q;
        for (const auto& [ch, count] : inDegree) {
            if (count == 0) {
                q.push(ch);
            }
        }

        std::string result = "";
        while (!q.empty()) {
            char curr = q.front();
            q.pop();
            result += curr;

            for (char neighbor : adj[curr]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Step 4: If result length does not match total unique characters, a cycle exists
        if (result.size() != inDegree.size()) {
            return "";
        }

        return result;
    }
};