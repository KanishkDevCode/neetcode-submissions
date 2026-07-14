class Solution {
public:

    bool solve(int index,
              vector<int>& nums,
              vector<int>& bucket,
              int target) {

        if(index == nums.size())
            return true;

        for(int i=0; i<bucket.size(); i++)  {

            if(bucket[i] + nums[index] > target)
                continue;
            
            bucket[i] += nums[index];

            if(solve(index+1, nums, bucket, target))
                return true;

            bucket[i] -= nums[index];

            if(bucket[i] == 0)
                break;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int sum  = 0;

        for(int x : nums)
            sum += x;

        if(sum % k != 0)
            return false;

        int target = sum / k;

        sort(nums.rbegin(), nums.rend());
        vector<int> bucket(k, 0);

        return solve(0, nums, bucket, target);
    }
};