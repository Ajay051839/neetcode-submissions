class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int itr=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=val && i!=itr){
                nums[itr]=nums[i];
                itr++;
            }else if(nums[i]!=val){
                itr++;
            }
        }
        return itr;
    }
};