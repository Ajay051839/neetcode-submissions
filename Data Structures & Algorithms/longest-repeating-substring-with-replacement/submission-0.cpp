class Solution {
public:
    int characterReplacement(string s, int k) {
        int start=0;
        int end=0;
        int n=s.size();
        unordered_map<char,int>mp;
        for(auto i:s){
            mp[i]++;
        }
        char cMx='A';
        for(auto i:mp){
          if(i.second>mp[cMx]){
            cMx=i.first;
          }
        }
        int ans=0;
        while(start<=end && end<n){
            if((1+end-start-mp[cMx])<=k){
                ans=max(ans,end-start+1);
                end++;
            }else{
                start++;
            }
        }
        return ans;

    }
};
