class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int>mp;
        int start=0;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])==mp.end()){
                nums[start++]=nums[i];
                mp[nums[i]]++;
            }else{
                continue;
            }
        }
        return start;
    }
};