class Solution {
public:

    vector<string> ans;
    string path;

    vector<string> mp = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };

    void solve(int index, string &digits) {

        if(index == digits.size()) {

            ans.push_back(path);
            return;
        }

        string letters = mp[digits[index] - '0'];

        for(char c : letters) {

            path.push_back(c);
            solve(index+1, digits);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        
        if(digits.empty())
            return {};

        solve(0, digits);

        return ans;
    }
};
