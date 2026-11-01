class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int>pq;
        int mx=INT_MIN;
        for(int i=0;i<k;i++){
            if(nums[i]>mx){
                mx=nums[i];
            }
            pq.push(nums[i]);
        }
        vector<int>ans;
        ans.push_back(pq.top());
        for(int i=k;i<nums.size();i++){
            if(nums[i-k]==pq.top()){
                pq.pop();
            }
            pq.push(nums[i]);
            ans.push_back(pq.top());
        }
        return ans;
        
    }
};
