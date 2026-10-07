class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        for (int i = 0; i < n; i++) {
            int rem = target - numbers[i];
            int start = i + 1;
            int end = n - 1;

            while (start <= end) {
                int mid = start + (end - start) / 2;

                if (numbers[mid] == rem) {
                    return {i + 1, mid + 1};
                } else if (numbers[mid] > rem) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
        }

        return {};
    }
};