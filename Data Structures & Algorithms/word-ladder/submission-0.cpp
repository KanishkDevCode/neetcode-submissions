class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        if (wordSet.find(endWord) == wordSet.end())
            return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        int L = beginWord.length();

        while (!q.empty()) {

            auto [curr, steps] = q.front(); // curr = "hit" & steps = 1
            q.pop();

            if (curr == endWord)
                return steps;

            for (int i=0; i < L; i++) {

                char originalChar = curr[i];

                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == originalChar) continue;

                    curr[i] = c;

                    if (wordSet.count(curr)) {
                        wordSet.erase(curr);
                        q.push({curr, steps + 1});
                    } 
                }

                curr[i] = originalChar;
            }
        }

        return 0;
    }
};