class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int sum = 0;

        for(int x : nums)
            sum += x;

        if (sum % 2)
            return false;

        int target =  sum / 2;

        int n = nums.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        dp[0][0] = true;

        for (int i=1; i<= n; i++) {

            for (int j=0; j <= target; j++) {

                dp[i][j] = dp[i-1][j];

                if (j >= nums[i-1])
                    dp[i][j] = dp[i][j] || dp[i-1][j - nums[i-1]];
            }
        }

        return dp[n][target];
    }
};
