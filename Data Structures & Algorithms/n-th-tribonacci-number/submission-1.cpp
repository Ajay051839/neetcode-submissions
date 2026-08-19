class Solution {
public:
    int Helper(int n, vector<int>& dp){
       if(n<=1)return n;
       if(n==2)return 1;
       if(dp[n]!=-1)return dp[n];
       return dp[n]=Helper(n-1,dp)+Helper(n-2,dp)+Helper(n-3,dp);
    }
    int tribonacci(int n) {
       vector<int>dp(n+1,-1);
       return Helper(n,dp);
    }
};