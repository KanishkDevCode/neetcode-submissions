class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if (s1.size() > s2.size())
            return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for (char c : s1)
            freq1[c - 'a']++;

        int window = s1.size();

        for (int i=0; i<window; i++) 
            freq2[s2[i] - 'a']++;

        if (freq1 == freq2)
            return true;

        for (int right = window; right < s2.size(); right++) {

            freq2[s2[right] - 'a']++;

            freq2[s2[right - window] - 'a']--;

            if (freq1 == freq2)
                return true;
        }

        return false;
    }
};
