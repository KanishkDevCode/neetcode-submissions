class Solution {
    int memo[101][101];
    int suffixSum[101];

    int helper(int i, int M, vector<int>& piles) {
        // Base Case: No piles left to pick
        if (i >= piles.size()) {
            return 0;
        }

        // Return saved result if already computed
        if (memo[i][M] != -1) {
            return memo[i][M];
        }

        int maxStones = 0;

        // Try taking X piles (from 1 up to 2 * M)
        for (int X = 1; X <= 2 * M && i + X <= piles.size(); X++) {
            int nextM = (X > M) ? X : M; // Update M = max(M, X)
            
            // My score = Total remaining stones - Opponent's optimal score
            int myStones = suffixSum[i] - helper(i + X, nextM, piles);
            
            if (myStones > maxStones) {
                maxStones = myStones;
            }
        }

        return memo[i][M] = maxStones;
    }

public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        // 1. Reset memoization table
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                memo[i][j] = -1;
            }
        }

        // 2. Pre-calculate total remaining stones from index i to end
        suffixSum[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        // 3. Start game from index 0 with M = 1
        return helper(0, 1, piles);
    }
};