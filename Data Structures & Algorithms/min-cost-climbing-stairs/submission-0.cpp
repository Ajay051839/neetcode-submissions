class Solution {
public:
    int minCost(int indx, const vector<int>& cost, vector<int>& dp) {
        if (indx <= 1) return 0;

        if (dp[indx] != -1) return dp[indx];

        int one = minCost(indx - 1, cost, dp) + cost[indx - 1];
        int two = minCost(indx - 2, cost, dp) + cost[indx - 2];

        return dp[indx] = min(one, two);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);

        return minCost(n, cost, dp);
    }
};