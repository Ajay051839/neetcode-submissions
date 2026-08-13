class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
           if(mp[nums[i]-1]!=0){
            mp[nums[i]]=mp[nums[i]-1]+1;
           }else{
            if(mp[nums[i]]==0){
            mp[nums[i]]++;
            }
           }
        }
        int ans=0;
        for(auto i:mp){
            ans=max(ans,i.second);
        }
        return ans;
    }
};
