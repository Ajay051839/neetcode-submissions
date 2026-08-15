class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int>preSum(nums.size());
        int ans=0;

        preSum[0]=nums[0];
        unordered_map<int,int>mp;
        mp[preSum[0]]++;
        if(nums[0]==k)ans++;
        for(int i=1;i<nums.size();i++){
            preSum[i]=preSum[i-1]+nums[i];
            if(preSum[i]==k)ans++;
            if(mp.find(preSum[i]-k)!=mp.end()){
                ans+=(mp[preSum[i]-k]);
            }
            mp[preSum[i]]++;
        }

        return ans;
    }
};