class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        vector<int> remainder_count(k, 0);

        remainder_count[0] = 1;

        int prefix_sum = 0;
        int result = 0;

        for (int num : nums) {

            prefix_sum += num;

            int rem = ((prefix_sum % k) + k) % k;

            result += remainder_count[rem];

            remainder_count[rem]++;
        }

        return result;
    }
};