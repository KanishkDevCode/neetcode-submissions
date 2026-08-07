class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if (prices.size() <= 1) return 0;

        int holding = -prices[0];
        int sold = 0;
        int rest = 0;

        for (size_t i = 1; i < prices.size(); ++i) {
            int prev_holding = holding;
            int prev_sold = sold;
            int prev_rest = rest;

            holding = max(prev_holding, prev_rest - prices[i]);

            sold = prev_holding + prices[i];

            rest = max(prev_rest, prev_sold);
        }

        return max(sold, rest);
    }
};
