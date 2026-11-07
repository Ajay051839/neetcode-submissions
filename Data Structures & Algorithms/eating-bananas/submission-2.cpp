class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int n=piles.size();
        if(n==h)return piles[n-1];
        int start=1;
        int end=piles[n-1];
        int ans=piles[n-1];
        while(start<=end){
            int mid=start+(end-start)/2;
            long long cnt=0;
            for(int i=0;i<n;i++){
                if(piles[i]%mid==0){
                    cnt+=(piles[i]/mid);
                }else{
                    cnt+=((piles[i]/mid)+1);
                }
            }
            if(cnt<=h){
                ans=min(ans,mid);
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return ans;

    }
};
