class Solution {
public:

    bool solve(int index, vector<int>& nums,
                vector<int>& side, int target) {
        
        if(index == nums.size())
            return true;

        for(int i=0; i<4; i++) {

            if(side[i] + nums[index] > target)
                continue;

            side[i] += nums[index];

            if(solve(index+1, nums, side, target))
                return true;

            side[i] -= nums[index];
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {

        int sum = 0; 

        for(int x : matchsticks)
            sum += x;

        if(sum % 4 != 0)
            return false;

        int target = sum / 4;

        sort(matchsticks.rbegin(), matchsticks.rend());
        vector<int> side(4, 0);
        return solve(0, matchsticks, side, target);    
    }
};