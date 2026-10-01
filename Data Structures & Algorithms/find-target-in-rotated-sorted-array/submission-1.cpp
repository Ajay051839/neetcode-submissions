class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int start=0;
        int end=n-1;
        int defPoint=-1;
        for(int i=0;i<(n-1);i++){
            if(nums[i]>nums[i+1]){
                defPoint=i;
            }
        }
        if(defPoint!=-1 && target>=nums[0] && target<=nums[defPoint]){
        end=defPoint;    
        }else if(defPoint!=-1){
          start=defPoint+1;
        }
        while(start<=end){
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                end = mid - 1; // Properly shrinks search range
            } else {
                start = mid + 1;
            }
        }
        return -1;
    }
};
