class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        
        int ans=INT_MIN;
        int start=0;
        int end=n-1;
        while(start<end){
            ans=max(ans,min(heights[start],heights[end])*(end-start));
            if(heights[start]<=heights[end]){
            start++;
            }else if(heights[end]<heights[start]){
                end--;
            }
        }
        return ans;
    }
};
