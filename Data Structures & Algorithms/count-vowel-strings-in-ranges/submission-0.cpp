class Solution {
public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {

        int n = words.size();

        vector<int> prefix(n);

        auto vowel = [](char c) {
            return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
        };

        prefix[0] =
            vowel(words[0][0]) &&
            vowel(words[0].back());

        for(int i=1;i<n;i++) {

            prefix[i]=prefix[i-1];

            if(vowel(words[i][0]) &&
               vowel(words[i].back()))

                prefix[i]++;
        }

        vector<int> ans;

        for(auto &q:queries){

            int l=q[0];
            int r=q[1];

            if(l==0)

                ans.push_back(prefix[r]);

            else

                ans.push_back(prefix[r]-prefix[l-1]);
        }

        return ans;
    }
};