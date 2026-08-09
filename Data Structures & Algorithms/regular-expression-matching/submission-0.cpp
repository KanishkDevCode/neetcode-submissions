class Solution {
    int memo[21][21]; // -1 = unvisited, 0 = false, 1 = true

    bool solve(int i, int j, string& s, string& p) {
        // Base case: If pattern is fully processed, check if string is also fully processed
        if (j == p.length()) {
            return i == s.length();
        }

        // Return memoized result if already calculated
        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        // Check if the current characters match
        bool firstMatch = (i < s.length()) && (s[i] == p[j] || p[j] == '.');

        bool result = false;

        // Case 1: The next character in pattern is '*'
        if (j + 1 < p.length() && p[j + 1] == '*') {
            // Option 1: Skip 'char*' (match 0 times) -> move pattern index by 2
            // Option 2: Use 'char*' (match 1 or more times) -> move string index by 1 if firstMatch holds
            result = solve(i, j + 2, s, p) || (firstMatch && solve(i + 1, j, s, p));
        } 
        // Case 2: Normal matching character or '.'
        else {
            result = firstMatch && solve(i + 1, j + 1, s, p);
        }

        return memo[i][j] = result;
    }

public:
    bool isMatch(string s, string p) {
        // Reset memoization table
        for (int i = 0; i <= s.length(); ++i) {
            for (int j = 0; j <= p.length(); ++j) {
                memo[i][j] = -1;
            }
        }

        return solve(0, 0, s, p);
    }
};