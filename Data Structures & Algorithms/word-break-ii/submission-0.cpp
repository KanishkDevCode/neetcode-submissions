class Solution {
public:

    unordered_set<string> dict;
    unordered_map<int, vector<string>> memo;

    vector<string> dfs(string &s, int start)
    {
        if(memo.count(start))
            return memo[start];

        vector<string> ans;

        if(start == s.size())
        {
            ans.push_back("");
            return ans;
        }
        for(int end = start; end < s.size(); end++)
        {
            string word = s.substr(start, end - start + 1);

            if(dict.count(word))
            {
                vector<string> suffix = dfs(s, end + 1);

                for(string sentence : suffix)
                {
                    if(sentence == "")
                        ans.push_back(word);
                    else
                        ans.push_back(word + " " + sentence);
                }
            }
        }

        memo[start] = ans;
        return ans;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        for(string word : wordDict)
            dict.insert(word);

        return dfs(s, 0);
    }
};