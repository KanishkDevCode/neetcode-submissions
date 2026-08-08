class Solution {
public:

    int maxCoins(vector<int>& nums) {

        int n = nums.size();

        // Add 1 to both ends
        vector<int> arr(n + 2, 1);

        for(int i = 0; i < n; i++) {
            arr[i + 1] = nums[i];
        }

        // dp[left][right]
        // maximum coins from bursting balloons
        // between left and right
        vector<vector<int>> dp(n + 2,
                               vector<int>(n + 2, 0));

        // Length = distance between left and right
        for(int len = 2; len < n + 2; len++) {

            for(int left = 0;
                left + len < n + 2;
                left++) {

                int right = left + len;

                // Try every possible last balloon
                for(int k = left + 1;
                    k < right;
                    k++) {

                    int coins =
                        dp[left][k]
                        + dp[k][right]
                        + arr[left] * arr[k] * arr[right];

                    dp[left][right] =
                        max(dp[left][right], coins);
                }
            }
        }

        return dp[0][n + 1];
    }
};