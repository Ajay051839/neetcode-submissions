class Solution {
public:
    void Merge(vector<int>& nums, int start, int mid, int end){
        int i=start;
        int j=mid+1;
        vector<int>arr;
        while(i<=mid && j<=end){
            if(nums[i]<=nums[j]){
               arr.push_back(nums[i]);
               i++;
            }else{
                arr.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
            arr.push_back(nums[i]);
               i++;
        }
        while(j<=end){
            arr.push_back(nums[j]);
                j++;
        }
        for(int i=0;i<arr.size();i++){
            nums[start+i]=arr[i];
        }
    }
    void MergeSort(vector<int>& nums, int start, int end){
        if(start>=end)return;
        int mid=(start+end)/2;
        MergeSort(nums,start,mid);
        MergeSort(nums,mid+1,end);
        Merge(nums,start,mid,end);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        MergeSort(nums,0,n-1);
        return nums;
    }
};