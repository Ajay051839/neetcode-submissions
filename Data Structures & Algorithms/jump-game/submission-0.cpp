class Solution {
public:
    bool Helper(int indx,vector<int>& nums,int n){
        if(indx==(n-1))return true;
        if(nums[indx]==0)return false;
        for(int i=1;i<=nums[indx];i++){
            if(Helper(indx+i,nums,n))return true;
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        return Helper(0,nums,n);
    }
};
