class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int c1 = 0, c2 = 1;
        int cnt1 = 0, cnt2 = 0;

        for(int x : nums) {

            if(x == c1)
                cnt1++;

            else if(x == c2)
                cnt2++;

            else if(cnt1 == 0){
                c1 = x;
                cnt1 = 1;
            }

            else if(cnt2 == 0){
                c2 = x;
                cnt2 = 1;
            }

            else{
                cnt1--;
                cnt2--;
            }
        }
        
        cnt1 = 0;
        cnt2 = 0;

        for(int x : nums){

            if(x == c1)
                cnt1++;

            else if(x == c2)
                cnt2++;
        }

        vector<int> ans;

        int limit = nums.size() / 3;

        if(cnt1 > limit)
            ans.push_back(c1);

        if(cnt2 > limit)
            ans.push_back(c2);

        return ans;
    }
};