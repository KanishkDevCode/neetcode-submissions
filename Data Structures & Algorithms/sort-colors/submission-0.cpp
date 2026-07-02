class Solution {
public:
    void sortColors(vector<int>& nums) {

        int cnt[3] = {0};

        for(int x : nums)
            cnt[x]++;

        int idx = 0;

        for(int i = 0; i<cnt[0]; i++)
            nums[idx++] = 0;

        for(int i=0; i<cnt[1]; i++)
            nums[idx++] = 1;

        for(int i=0; i<cnt[2]; i++)
            nums[idx++] = 2;
        
    }
};