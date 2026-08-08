#include <vector>
#include <numeric>
#include <cmath>

class Solution {
public:
    int findTargetSumWays(std::vector<int>& nums, int target) {
        int totalSum = std::accumulate(nums.begin(), nums.end(), 0);

        // Edge Cases:
        // 1. Target is impossible if totalSum is smaller than abs(target)
        // 2. (target + totalSum) must be non-negative and even
        if (std::abs(target) > totalSum || (target + totalSum) % 2 != 0 || (target + totalSum) < 0) {
            return 0;
        }

        int subsetSum = (target + totalSum) / 2;

        // 1D DP array to count subsets that sum up to `subsetSum`
        std::vector<int> dp(subsetSum + 1, 0);
        dp[0] = 1; // Base case: 1 way to make sum 0 (empty subset)

        for (int num : nums) {
            // Iterate backwards to prevent using the same element multiple times
            for (int j = subsetSum; j >= num; --j) {
                dp[j] += dp[j - num];
            }
        }

        return dp[subsetSum];
    }
};