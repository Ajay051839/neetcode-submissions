class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n<=1)return 0;
        vector<int> leftmx(n);
        leftmx[0]=height[0];
        for(int i=1;i<n;i++){
            leftmx[i]=max(leftmx[i-1],height[i]);
        }
        vector<int>rightmx(n);
        rightmx[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
           rightmx[i]=max(rightmx[i+1],height[i]);
        }
        int water=0;
        for(int i=0;i<n;i++){
            water+=(min(leftmx[i],rightmx[i])-height[i]);
        }
        return water;

    }
};
