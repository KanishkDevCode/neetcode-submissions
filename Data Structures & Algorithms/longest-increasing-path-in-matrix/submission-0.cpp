class Solution {
public:

    int dfs(vector<vector<int>>& matrix, int r, int c, vector<vector<int>>& dp) {
        
        if (dp[r][c] != 0)
            return dp[r][c];

        int rows = matrix.size();
        int cols = matrix[0].size();

        int best = 1;
        
        // Directions
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {

            int nr = r + dr[i];
            int nc = c + dc[i];

            // Boundaries
            if (nr >= 0 && nr < rows &&
                nc >= 0 && nc < cols) {

                    // Strictly Increasing
                    if (matrix[nr][nc] > matrix[r][c]) {

                        best = max(best, 1 + dfs(matrix, nr, nc, dp));
                    }
                }
        }
        
        dp[r][c] = best;

        return best;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        int answer = 0;

        // Trying every cell as starting point
        for (int r = 0; r < rows; r++) {

            for (int c = 0; c < cols; c++) {

                answer = max(answer, dfs(matrix, r, c, dp));
            }
        }

        return answer;
    }
};
