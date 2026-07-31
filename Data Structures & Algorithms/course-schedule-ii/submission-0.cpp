class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        // Adjacency list
        vector<vector<int>> graph(numCourses);

        // Indegree array
        vector<int> indegree(numCourses, 0);

        // Build graph and indegree
        for (auto &p : prerequisites) {
            int course = p[0];
            int prereq = p[1];

            graph[prereq].push_back(course);
            indegree[course]++;
        }

        // Queue for courses with no prerequisites
        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> ans;

        // Kahn's Algorithm (BFS)
        while (!q.empty()) {

            int node = q.front();
            q.pop();

            ans.push_back(node);

            // Reduce indegree of neighbors
            for (int neighbor : graph[node]) {

                indegree[neighbor]--;

                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        // If all courses are processed, return the order
        if (ans.size() == numCourses)
            return ans;

        // Cycle exists
        return {};
    }
};