class Solution {
public:
    bool Helper(int indx, vector<int>& nums, int n, vector<int>& dp) {
        if (indx >= n - 1) return true;
        if (nums[indx] == 0) return false;
        if (dp[indx] != -1) return dp[indx];

        for (int i = 1; i <= nums[indx]; i++) {
            if (Helper(indx + i, nums, n, dp)) {
                return dp[indx] = true;
            }
        }

        return dp[indx] = false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return true;

        vector<int> dp(n, -1); // -1: unvisited, 0: false, 1: true
        return Helper(0, nums, n, dp);
    }
};