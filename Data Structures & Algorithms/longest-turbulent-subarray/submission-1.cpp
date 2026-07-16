class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        
        int n = arr.size();

        if (n == 1)
            return 1;

        int ans = 1;
        int currLen = 1;
        int prevCmp = 0;

        for (int i = 1; i < n; i++) {

            int currCmp = 0;

            if (arr[i] > arr[i-1])
                currCmp = 1;
            else if (arr[i] < arr[i-1])
                currCmp = -1;

            if (currCmp == 0) {
                currLen = 1;
            }
            else if (prevCmp * currCmp == -1) {
                currLen++;
            }
            else {
                currLen = 2;
            }

            ans = max(ans, currLen);
            prevCmp = currCmp;
        }

        return ans;
    }
};