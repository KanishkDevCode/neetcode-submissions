class Solution {
public:
    string customSortString(string order, string s) {
        
        vector<int> freq(26, 0);

        // charaters in s
        for (char c : s)
            freq[c - 'a']++;

        string ans;

        // Adding Custom Charater
        for (char c : order) {
            while (freq[c - 'a'] > 0) {
                ans += c;
                freq[c - 'a']--;
            }
        }

        // Add remaniing charater
        for (int i=0; i < 26; i++) {
            while (freq[i] > 0) {
                ans += char(i + 'a');
                freq[i]--;
            }
        }

        return ans;
    }
};