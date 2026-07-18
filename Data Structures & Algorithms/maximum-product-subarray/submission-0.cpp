class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int global_max = nums[0];
        int current_max = nums[0];
        int current_min = nums[0];

        for (size_t i = 1; i < nums.size(); i++) {
            int val = nums[i];

            if (val < 0) {
                swap(current_max, current_min);
            }

            current_max = max(val, current_max * val);
            current_min = min(val, current_min * val);

            global_max = max(global_max, current_max);
        }

        return global_max;
    }
};
