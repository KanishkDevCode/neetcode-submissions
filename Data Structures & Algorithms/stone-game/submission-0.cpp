class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        
        int n = piles.size();
        vector<int> dp(n, 0);

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = piles[i]; // Base case: subarray of length 1 (piles[i..i])
            
            for (int j = i + 1; j < n; j++) {
                // dp[j] on right side is old dp[i+1][j]   (Option 1: Pick left pile)
                // dp[j-1] is current dp[i][j-1]           (Option 2: Pick right pile)
                dp[j] = max(piles[i] - dp[j], piles[j] - dp[j - 1]);
            }
        }

        return dp[n - 1] > 0; // True if Alice's relative score is positive
        
    }
};