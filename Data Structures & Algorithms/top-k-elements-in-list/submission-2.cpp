class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }

        // Min-heap storing pair<frequency, element>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

        for (const auto& [num, count] : mp) {
            min_heap.push({count, num});
            if (min_heap.size() > k) {
                min_heap.pop(); // Remove the element with the smallest frequency
            }
        }

        vector<int> ans;
        while (!min_heap.empty()) {
            ans.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return ans;
    }
};