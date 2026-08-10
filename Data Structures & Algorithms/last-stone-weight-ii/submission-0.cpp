class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        
        int total = 0;

        for (int stone : stones)
            total += stone;

        int target = total / 2;

        vector<bool> dp(target + 1, false);

        dp[0] = true;

        for (int stone : stones) {

            for (int j = target; j >= stone; j--) {

                dp[j] = dp[j] || dp[j - stone];
            }
        }

        int best = 0;

        for (int j = target; j >= 0; j--) {

            if (dp[j]) {
                best = j;
                break;
            }
        }

        return total - 2 * best;
    }
};