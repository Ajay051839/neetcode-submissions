class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero=0;
        int one=0;
        int two=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0)zero++;
            if(nums[i]==1)one++;
            if(nums[i]==2)two++;
        }
        int indx=0;
        while(zero){
            nums[indx]=0;
            indx++;
            zero--;
        }
        while(one){
            nums[indx]=1;
            indx++;
            one--;
        }
        while(two){
            nums[indx]=2;
            indx++;
            two--;
        }
        

    }
};