class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> prev(5, 0), curr(5, 0);
        
        for (int i = n - 1; i >= 0; i--) {
            for (int limit = 1; limit < 5; limit++) {
                int profit = 0;
                if (limit % 2 == 0) {
                    profit = max(-prices[i] + prev[limit - 1], prev[limit]);
                } else {
                    profit = max(prices[i] + prev[limit - 1], prev[limit]);
                }
                curr[limit] = profit;
            }
            prev = curr;
        }
        return prev[4];
    }
};