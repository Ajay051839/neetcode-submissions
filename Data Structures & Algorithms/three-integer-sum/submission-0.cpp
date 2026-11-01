class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        set<vector<int>>st;
        for(int i=1;i<n;i++){
            int sum=nums[i-1]+nums[i];
            for(int j=i+1;j<n;j++){
                if(sum+nums[j] == 0){
                    st.insert({nums[i-1],nums[i],nums[j]});
                }
            }
        }
        for(auto i:st){
            ans.push_back(i);
        }
        return ans;
    }
};
