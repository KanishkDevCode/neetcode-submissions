#include <algorithm>
using namespace std;

class TrieNode {
public:
    TrieNode* child[26];
    bool isEnd;

    TrieNode() {
        for (int i = 0; i < 26; i++)
            child[i] = nullptr;
        isEnd = false;
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();

    int dp[55];

    void insert(string word) {
        TrieNode* curr = root;

        for (char c : word) {
            int idx = c - 'a';

            if (curr->child[idx] == nullptr)
                curr->child[idx] = new TrieNode();

            curr = curr->child[idx];
        }

        curr->isEnd = true;
    }

    int solve(int i, string &s) {

        if (i == s.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        
        int ans = 1 + solve(i + 1, s);

        TrieNode* curr = root;

        for (int j = i; j < s.size(); j++) {

            int idx = s[j] - 'a';

            if (curr->child[idx] == nullptr)
                break;

            curr = curr->child[idx];

            if (curr->isEnd)
                ans = min(ans, solve(j + 1, s));
        }

        return dp[i] = ans;
    }

    int minExtraChar(string s, vector<string>& dictionary) {

        fill(dp, dp + 55, -1);   

        for (string &word : dictionary)
            insert(word);

        return solve(0, s);
    }
};