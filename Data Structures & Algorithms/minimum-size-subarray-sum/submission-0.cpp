class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minL = INT_MAX;
        int currSum = 0;
        int start = 0;

        for (int end = 0; end < nums.size(); end++) {
            currSum += nums[end];

            // Shrink window from the left as much as possible 
            // while the condition is still satisfied
            while (currSum >= target) {
                minL = min(minL, end - start + 1);
                currSum -= nums[start];
                start++;
            }
        }

        return minL == INT_MAX ? 0 : minL;
    }
};