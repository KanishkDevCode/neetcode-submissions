class Solution {
public:

    vector<vector<int>> ans;
    vector<int> path;

    void solve(int index, vector<int>& nums) {

        if(index == nums.size()) {

            ans.push_back(path);
            return;
        }

        path.push_back(nums[index]);

        solve(index + 1, nums);

        path.pop_back();

        solve(index + 1, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        solve(0, nums);
        return ans;
    }
};
