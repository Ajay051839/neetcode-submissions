class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int mn=INT_MIN;
        int mx=0;
        for(int i=0;i<n;i++){
            mx+=weights[i];
            mn=max(mn,weights[i]);
        }
        int ans=INT_MAX;
        while(mn<=mx){
            int mid=mn+(mx-mn)/2;
            int left=mid;
            int cnt=1;
            for(int i=0;i<n;i++){
              if(left>=weights[i]){
                  left-=weights[i];
              }else{
                left=mid;
                left-=weights[i];
                cnt++;
              }
            }
            if(cnt>days){
                mn=mid+1;
            }else{
                ans=min(ans,mid);
                mx=mid-1;
            }
        }
        return ans;
    }
};