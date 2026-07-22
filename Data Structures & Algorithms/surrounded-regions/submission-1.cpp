class Solution {
public:

    int m, n;

    void dfs(vector<vector<char>>& board, int r, int c) {

        if(r<0 || r>=m || c<0 || c>=n)
            return;

        if(board[r][c] != 'O')
            return;

        board[r][c] = '#';

        dfs(board, r+1, c);
        dfs(board, r-1, c);
        dfs(board, r, c+1);
        dfs(board, r, c-1);
    }
    void solve(vector<vector<char>>& board) {
        
        m = board.size(); // no of rows
        n = board[0].size(); // no of cols

        // left & right
        for(int i=0; i<m; i++){

            if(board[i][0] == 'O')
                dfs(board, i, 0);

            if(board[i][n-1] == 'O')
                dfs(board, i, n-1);
        }

        // top & right
        for(int j=0; j<n; j++) {
            
            if(board[0][j] == 'O')
                dfs(board, 0, j);

            if(board[m-1][j] == 'O')
                dfs(board, m-1, j);
        }

        // flip cells
        for (int i=0; i<m; i++) {

            for (int j=0; j<n; j++) {

                if(board[i][j] == 'O')
                    board[i][j] = 'X';

                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};
