class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int rows = heights.size();
        int cols = heights[0].size();

        // // Matrix to store the minimum effort required to reach each cell
        vector<vector<int>> effort(rows, vector<int>(cols, INT_MAX));

        // Min-heap priority queue storing {current_effort, {row, col}}
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> pq;

        effort[0][0] = 0;
        pq.push({0, {0, 0}});

        // Directions
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!pq.empty()) {

            auto[currEffort, cell] = pq.top();
            pq.pop();
            int r = cell.first;
            int c = cell.second;

            // Reached the destinaton (bottom-right cell)
            if (r == rows-1 && c == cols-1)
                return currEffort;

            // Skip if we already found a path with strictly smaller effort
            if (currEffort > effort[r][c])
                continue;

            // Explore all 4-Directions
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                // Check grid boundaries
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                    
                    // Maximum height difference along this path segment
                    int nextEffort = 
                        max(currEffort, abs(heights[r][c] - heights[nr][nc]));

                    // If this path offers a smaller max effort to reach (nr, nc), update and push
                    if (nextEffort < effort[nr][nc]) {
                        effort[nr][nc] = nextEffort;
                        pq.push({nextEffort, {nr, nc}});
                    }
                }
            }
        }

        return 0;
    }
};