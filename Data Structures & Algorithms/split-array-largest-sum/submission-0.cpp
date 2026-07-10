class Solution {
public:
    bool canSplit(vector<int>& nums, int k, int maxSum) {
        
        int subarrays = 1;
        int currentSum = 0;

        for (int num : nums) {

            if (currentSum + num > maxSum) {
                subarrays++;
                currentSum = 0;
            }

            currentSum += num;
        }
        return subarrays <= k;
    }

    int splitArray(vector<int>& nums, int k) {

        int left = *max_element(nums.begin(), nums.end());

        int right = accumulate(nums.begin(), nums.end(), 0);

        while (left < right) {

            int mid = left + (right - left) / 2;

            if (canSplit(nums, k, mid))
                right = mid;
            else 
                left = mid + 1;
        }
        return left;
    }
};