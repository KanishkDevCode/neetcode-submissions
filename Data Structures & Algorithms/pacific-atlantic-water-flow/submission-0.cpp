class Solution {
public:

    int m, n;
    vector<vector<int>> heights;

    void dfs(int r, int c, vector<vector<bool>>& vis) {

        vis[r][c] = true;

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};
        
        for(int k=0; k<4; k++) {

            int nr = r+dr[k];
            int nc = c+dc[k];

            if(nr<0 || nr>=m || nc<0 || nc>=n)
                continue;

            if(vis[nr][nc])
                continue;

            if(heights[nr][nc] < heights[r][c])
                continue;

            dfs(nr, nc, vis); 
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        
        heights = h;
        m = h.size();
        n = h[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        //Pacific
        for(int i=0; i<m; i++)
            dfs(i, 0, pacific);

        for(int j=0; j<n; j++)
            dfs(0, j, pacific);

        //Atlantic
        for(int i=0; i<m; i++)
            dfs(i, n-1, atlantic);

        for(int j=0; j<n; j++)
            dfs(m-1, j, atlantic);

        vector<vector<int>> ans;

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});

        return ans;
    }
};
