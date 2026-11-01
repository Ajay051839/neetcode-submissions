class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        // vector<int>nextGreaterLeft(n);
        // vector<int>nextGreaterRight(n);
        // nextGreaterLeft[0]=heights[0];
        // for(int i=1;i<n;i++){
        //    nextGreaterLeft[i]=max(nextGreaterLeft[i-1],heights[i]);
        // }
        // nextGreaterRight[n-1]=heights[n-1];
        // for(int i=n-2;i>=0;i--){
        //    nextGreaterRight[i]=max(nextGreaterRight[i+1],heights[i]);
        // }
        int ans=INT_MIN;
        int start=0;
        int end=n-1;
        while(start<end){
            ans=max(ans,min(heights[start],heights[end])*(end-start));
            ans=max(ans,min(heights[start+1],heights[end])*(end-start-1));
            ans=max(ans,min(heights[start],heights[end-1])*(end-start-1));
            start++;
            end--;
        }
        return ans;
    }
};
