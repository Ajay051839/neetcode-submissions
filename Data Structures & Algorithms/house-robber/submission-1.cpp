class Solution {
public:
    int Helper(int indx,const vector<int>& nums,vector<int>& dp,int n){
        if(indx==1)return max(nums[indx],nums[indx-1]);
        if(indx==0)return nums[0];
        if(dp[indx]!=-1)return dp[indx];
        //take
        int take=0;
        if(indx>=2){
        take=nums[indx]+Helper(indx-2,nums,dp,n);
        }
        //not take
        int notTake=Helper(indx-1,nums,dp,n);
        return dp[indx]=max(take,notTake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return Helper(n-1,nums,dp,n);
        
    }
};
