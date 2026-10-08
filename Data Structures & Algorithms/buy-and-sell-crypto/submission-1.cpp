class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans=0;
        for(int i=0;i<(n-1);i++){
            if(prices[i]<prices[i+1]){
                int start=i;
                while((i+1)<n && prices[start]<prices[i+1]){
                    ans=max(ans,prices[i+1]-prices[start]);
                    i++;
                }
                i--;
            }
        }
        return ans;
    }
};
