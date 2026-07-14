class Solution {
public:

    int ans = 0;

    void solve(int index, int currXor, vector<int>& nums) {

        if(index == nums.size()){

            ans += currXor;
            return;
        }

        solve(index + 1, currXor ^ nums[index], nums);

        solve(index + 1, currXor, nums);
    }
    int subsetXORSum(vector<int>& nums) {
        
        solve(0, 0, nums);
        return ans;
    }
};