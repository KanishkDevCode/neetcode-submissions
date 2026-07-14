class Solution {
public:

    vector<vector<int>> ans;
    vector<int> path;

    void solve(int index, int target, vector<int>& nums) {

        if(target == 0) {

            ans.push_back(path);
            return;
        }

        for(int i=index; i<nums.size(); i++) {

            if(i>index && nums[i] == nums[i-1])
                continue;

            if(nums[i]>target)
                break;

            path.push_back(nums[i]);

            solve(i+1, target-nums[i], nums);

            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());

        solve(0, target, nums);

        return ans;
    }
};
