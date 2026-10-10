class Solution {
public:
    void Helper(int indx, int n, vector<int>& nums, int target, vector<int>& temp, vector<vector<int>>& ans) {
        // Base Case 1: Success
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        
        // Base Case 2: Out of bounds or target exceeded
        if (indx == n || target < 0) {
            return;
        }

        // Choice 1: Include nums[indx] (stay at indx to allow duplicate pick)
        if (nums[indx] <= target) {
            temp.push_back(nums[indx]);
            Helper(indx, n, nums, target - nums[indx], temp, ans);
            temp.pop_back(); // Backtrack
        }

        // Choice 2: Exclude nums[indx] (move to indx + 1)
        Helper(indx + 1, n, nums, target, temp, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        Helper(0, nums.size(), nums, target, temp, ans);
        return ans;
    }
};