class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
        vector<int> rank(26);

        for (int i = 0; i < 26; i++) 
            rank[order[i] - 'a'] = i;

        for (int i = 0; i+1 < words.size(); i++ ) {
            string &a = words[i];
            string &b = words[i + 1];

            int len = min(a.size(), b.size());
            bool found = false;

            for (int j = 0; j < len; j++) {
                if (a[j] != b[j]) {
                    if (rank[a[j] - 'a'] > rank[b[j] - 'a'])
                        return false;

                    found = true;
                    break;
                }
            }

            if (!found && a.size() > b.size())
                return false;
        }
        
        return true;
    }
};