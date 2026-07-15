class Solution {
public:

    int ans = 0;

    void solve(int row,
               int n,
               vector<int>& col,
               vector<int>& diag,
               vector<int>& anti)
    {
        if(row == n)
        {
            ans++;
            return;
        }

        for(int c=0;c<n;c++)
        {
            if(col[c] || diag[row-c+n-1] || anti[row+c])
                continue;

            col[c]=1;
            diag[row-c+n-1]=1;
            anti[row+c]=1;

            solve(row+1,n,col,diag,anti);

            col[c]=0;
            diag[row-c+n-1]=0;
            anti[row+c]=0;
        }
    }

    int totalNQueens(int n) {

        vector<int> col(n,0);
        vector<int> diag(2*n-1,0);
        vector<int> anti(2*n-1,0);

        solve(0,n,col,diag,anti);

        return ans;
    }
};