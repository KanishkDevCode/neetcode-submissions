class Solution {
public:

    long long solve(string& s, string& t,
                    int i, int j,
                    vector<vector<long long>>& dp) {
        
        // Successfilly matched all of t
        if (j == t.size())
            return 1;

        // s if finished but t is not
        if (i == s.size())
            return 0;

        // Already calculated
        if (dp[i][j] != -1)
            return dp[i][j];

        long long ans = 0;

        // Option 1 : skip s[i]
        ans = solve(s, t, i + 1, j, dp);

        // Option 2 : use s[i] of charaters match
        if (s[i] == t[j])
            ans += solve(s, t, i + 1, j + 1, dp);

        return dp[i][j] = ans;
    }

    int numDistinct(string s, string t) {
        
        int n = s.size();
        int m = t.size();

        vector<vector<long long>> dp(n, vector<long long>(m, -1));

        return solve(s, t, 0, 0, dp);
    }
};
