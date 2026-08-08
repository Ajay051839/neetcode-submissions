class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        priority_queue<pair<int, int>>pq;
        for(auto i:mp){
            pq.push({i.second,i.first});
        }
        vector<int>ans;
        for(int i=0; i<k;i++){
          int k=pq.top().second;
          pq.pop();
          ans.push_back(k);
        }
        return ans;
    }
};
