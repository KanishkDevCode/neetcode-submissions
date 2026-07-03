class NumMatrix {
public:

    vector<vector<int>> pref;

    NumMatrix(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        pref.assign(m+1, vector<int>(n+1, 0));

        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {

                pref[i][j] = 
                    matrix[i-1][j-1]
                    + pref[i-1][j]
                    + pref[i][j-1]
                    - pref[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        row1++;
        col1++;
        row2++;
        col2++;

        return pref[row2][col2]
            - pref[row1 - 1][col2]
            - pref[row2][col1 - 1]
            + pref[row1 - 1][col1 - 1];
    }
};