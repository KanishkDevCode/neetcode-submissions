class Solution {
public:

    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> visited;

    void solve(vector<int>& nums) {

        if(path.size() == nums.size()) {

            ans.push_back(path);
            return;
        }

        for(int i=0; i<nums.size(); i++) {

            if(visited[i])
                continue;

            visited[i] = true;

            path.push_back(nums[i]);

            solve(nums);

            path.pop_back();

            visited[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        visited.assign(nums.size(),false);

        solve(nums);

        return ans;
    }
};
