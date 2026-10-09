class Solution {
public:
    void Helper(vector<int>& nums,int indx,int n,vector<vector<int>> &ans,vector<int>& temp){
        if(indx==n){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[indx]);
        Helper(nums,indx+1,n,ans,temp);
        temp.pop_back();
        Helper(nums,indx+1,n,ans,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        vector<int>temp;
        Helper(nums,0,n,ans,temp);
        return ans;
    }
};
