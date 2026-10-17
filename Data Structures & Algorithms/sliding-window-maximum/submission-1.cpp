class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int>pq;
        unordered_map<int,int>mp;
        for(int i=0;i<k;i++){
            pq.push(nums[i]);
            mp[nums[i]]++;
        }
        vector<int>ans;
        ans.push_back(pq.top());
        for(int i=k;i<nums.size();i++){
            mp[nums[i]]++;
            if(nums[i-k]==pq.top()){
                pq.pop();
            }
            mp[nums[i-k]]--;
            pq.push(nums[i]);
            if(mp[pq.top()]!=0){
            ans.push_back(pq.top());
            }else{
                while(mp[pq.top()]==0){
                    pq.pop();
                }
                if(!pq.empty()){
                    ans.push_back(pq.top());
                }
            }
        }
        return ans;
        
    }
};
