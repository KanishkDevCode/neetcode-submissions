class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int m = word1.length();
        int n = word2.length();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i=0; i <= m; i++) dp[i][0] = i; // Deleting all chars from word1
        for (int j=0; j <= n; j++) dp[0][j] = j; // Inserting all chars from word1

        for (int i=1; i <= m; i++) {
            
            for (int j=1; j <= n; j++) {

                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1]; // char matches no operation
                }
                else {
                    dp[i][j] = 1 +
                               min({dp[i-1][j],  // Delete
                                   dp[i][j-1],  // Insert
                                   dp[i-1][j-1] // Replace)
                               });
                }
            }
        }
        return dp[m][n];
    }
};