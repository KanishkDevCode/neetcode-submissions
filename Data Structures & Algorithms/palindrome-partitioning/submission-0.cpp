class Solution {
public:

    vector<vector<string>> ans;
    vector<string> path;

    bool isPalindrome(string &s, int left, int right) {

        while(left < right) {

            if(s[left] != s[right])
                return false;

            left++;
            right--;
        }

        return true;
    }

    void solve(int index, string &s) {

        if(index == s.size()) {

            ans.push_back(path);
            return;
        }

        for(int end = index; end<s.size(); end++) {

            if(isPalindrome(s, index, end)) {

                path.push_back(s.substr(index, end-index+1));
                solve(end+1, s);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        
        solve(0, s);
        return ans;
    }
};
