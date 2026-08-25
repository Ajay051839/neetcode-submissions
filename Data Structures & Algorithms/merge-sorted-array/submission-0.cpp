class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int start1=0;
        int start2=0;
        vector<int>temp(m+n);
        int start=0;
        while(start1<m && start2<n){
           if(nums1[start1]<=nums2[start2]){
            temp[start++]=nums1[start1++];
           }else{
            temp[start++]=nums2[start2++];
           }
        }
        while(start1<m){
            temp[start++]=nums1[start1++];
        }
        while(start2<n){
            temp[start++]=nums2[start2++];
        }
        nums1=temp;
    }
};