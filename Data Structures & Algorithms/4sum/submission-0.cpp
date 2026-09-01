class Solution {
    using v = vector<int>;
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<v> st;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                unordered_set<long long> hashset; // unordered_set is faster O(1)
                for (int k = j + 1; k < n; k++) {
                    long long sum = (long long)nums[i] + nums[j] + nums[k];
                    long long elem = (long long)target - sum;

                    if (hashset.find(elem) != hashset.end()) {
                        v temp = {nums[i], nums[j], nums[k], (int)elem};
                        sort(temp.begin(), temp.end()); // Crucial for deduplication
                        st.insert(temp);
                    }
                    hashset.insert(nums[k]);
                }
            }
        }
        return vector<v>(st.begin(), st.end());
    }
};