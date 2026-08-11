class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> preProd(n,1);
        vector<int> suffProd(n,1);

        for (int i = 1; i < n; i++) {
           preProd[i]=preProd[i-1]*nums[i-1];
        }
        for (int i = n-2; i>=0; i--) {
           suffProd[i]=suffProd[i+1]*nums[i+1];
        }

        vector<int>ans(n);
        for(int i=0; i<n; i++){
          ans[i]=preProd[i]*suffProd[i];
        }
        return ans;
    }
};
