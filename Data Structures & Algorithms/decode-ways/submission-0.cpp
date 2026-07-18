class Solution {
public:
    int numDecodings(string s) {
        
        if (s.empty() || s[0] == '0') return 0;

        int n = s.length();
        int prev2 = 1;
        int prev1 = 1;

        for (int i=1; i < n; i++) {
            int current_ways = 0;

            if (s[i] != '0') {
                current_ways += prev1;
            }

            int two_digit = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if (two_digit >= 10 && two_digit <= 26) {
                current_ways += prev2;
            }

            prev2 = prev1;
            prev1 = current_ways;
        }

        return prev1;
    }
};
