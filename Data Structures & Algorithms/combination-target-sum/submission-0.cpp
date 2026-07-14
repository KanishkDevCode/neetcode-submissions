class Solution {
public:

    vector<vector<int>> ans;
    vector<int> path;

    void solve(int index, int target, vector<int>& nums) {

        if(target == 0){

            ans.push_back(path);
            return;
        }

        if(index == nums.size() || target < 0)
            return;

        path.push_back(nums[index]);

        solve(index, target-nums[index], nums);

        path.pop_back();

        solve(index+1, target, nums);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        solve(0, target, nums);
        return ans;
    }
};
