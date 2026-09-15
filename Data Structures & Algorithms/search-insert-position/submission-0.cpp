class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        if (nums[start] > target) return 0;
        if (nums[end] < target) return n;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) return mid;
        else if (nums[mid] < target && nums[mid + 1] > target) {
            return mid+1;
        }
        else if (nums[mid] > target) {
            end = mid - 1;
        }
        else if (nums[mid] < target) {
            start = mid + 1;
        }
    }
    return n;
}
}
;