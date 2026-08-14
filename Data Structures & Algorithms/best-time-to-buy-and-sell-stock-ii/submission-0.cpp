#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int max_profit = 0;

        for (size_t i = 1; i < prices.size(); ++i) {
            // If the price increased compared to yesterday, take the profit
            if (prices[i] > prices[i - 1]) {
                max_profit += prices[i] - prices[i - 1];
            }
        }

        return max_profit;
    }
};