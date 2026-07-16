class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int total = 0;

        int currMax = 0;
        int currMin = 0;

        int maxSum = nums[0];
        int minSum = nums[0];

        for (int num : nums) {

            currMax = max(num, currMax + num);
            maxSum = max(maxSum, currMax);

            currMin = min(num, currMin + num);
            minSum = min(minSum, currMin);

            total += num;
        }

        if(maxSum < 0)
            return maxSum;

        return max(maxSum, total - minSum);
    }
};