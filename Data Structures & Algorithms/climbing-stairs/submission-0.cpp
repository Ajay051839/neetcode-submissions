class Solution {
public:
    int Helper(vector<int>& dp,int n){
        if(n<=1){
            return 1;
        }
        if(dp[n]!=-1)return dp[n];
        return dp[n]=Helper(dp,n-1)+Helper(dp,n-2);
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return Helper(dp,n);
    }
};
