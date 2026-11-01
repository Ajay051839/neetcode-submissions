class Solution {
   public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int currSum = 0;
        int start = 0;
        for (int i = 0; i < 2 * n; i++) {
            if (start != (i % n)) {
                currSum += (nums[(i % n)]);
            } else {
                start = -1;
                currSum = 0;
            }
            if (start == -1) start = ((i % n));
            ans = max(ans, currSum);
            if (currSum < 0) {
                currSum = 0;
                start = -1;
            }
        }
        return ans;
    }
};
// currSum=2 start=0, currS
