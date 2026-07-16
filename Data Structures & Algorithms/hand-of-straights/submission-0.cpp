class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        int n = hand.size();

        if (n % groupSize != 0)
            return false;

        unordered_map<int, int> freq;

        for (int card : hand)
            freq[card]++;

        sort(hand.begin(), hand.end());

        for (int card : hand) {

            if (freq[card] == 0)
                continue;

            for (int i=0; i < groupSize; i++) {

                if (freq[card + i] == 0)
                    return false;

                freq[card + i]--;
            }
        }  

        return true;
    }
};
