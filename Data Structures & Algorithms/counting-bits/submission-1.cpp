class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>dp(n+1);
        dp[0]=0;
        if(n==0)return dp;
        dp[1]=1;
        if(n==1)return dp;
        dp[2]=1;
        if(n==2)return dp;
        dp[3]=2;
        if(n==3)return dp;
        int start=4;
        for(int i=4;i<=n;i++){
            if(i%start!=0){
            dp[i]=1+dp[i-4];
            }else{
                dp[i]=1;
                start=start<<1;
            }
        }
        return dp;
    }
};

//1  <<10 <<100 <<1

