class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int>mp;
        for(auto i:nums){
            if(mp.find(i)!=mp.end()){
                return i;
            }
            mp[i]++;
            
        }
        return -1;
    }
};
