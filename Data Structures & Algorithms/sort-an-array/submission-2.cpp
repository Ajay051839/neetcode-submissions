class Solution {
public:
    void Merge(int start, int mid, int end, vector<int>& nums) {
        vector<int> temp(end - start + 1);
        int itr = 0;
        int i = start;      // Pointer for the left subarray
        int j = mid + 1;    // Pointer for the right subarray

        // Merge the two halves into temp
        while (i <= mid && j <= end) {
            if (nums[i] <= nums[j]) {
                temp[itr++] = nums[i++];
            } else {
                temp[itr++] = nums[j++];
            }
        }

        // Copy remaining elements from the left subarray, if any
        while (i <= mid) {
            temp[itr++] = nums[i++];
        }

        // Copy remaining elements from the right subarray, if any
        while (j <= end) {
            temp[itr++] = nums[j++];
        }

        // Copy the sorted elements back to the original array
        for (int k = 0; k < temp.size(); k++) {
            nums[start + k] = temp[k];
        }
    }

    void MergeSort(int start, int end, vector<int>& nums) {
        if (start >= end) return;
        int mid = start + (end - start) / 2;
        MergeSort(start, mid, nums);
        MergeSort(mid + 1, end, nums);
        Merge(start, mid, end, nums);
    }

    vector<int> sortArray(vector<int>& nums) {
        MergeSort(0, nums.size() - 1, nums);
        return nums;
    }
};