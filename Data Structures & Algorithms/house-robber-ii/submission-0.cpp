class Solution {
public:

    int robLinear(vector<int>& nums, int start, int end) {

        int prev2 = 0;
        int prev1 = 0;

        for (int i = start; i <= end; i++) {
            int current_max = std::max(prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1 = current_max;
        }

        return prev1;
    }
    int rob(vector<int>& nums) {
        
        int n = nums.size();

        if (n == 1) return nums[0];

        int skipLastHouse = robLinear(nums, 0, n-2);
        int skipFirstHouse = robLinear(nums, 1, n-1);

        return max(skipLastHouse, skipFirstHouse);
    }
};
