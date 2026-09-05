class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        int ans=0;
        int cnt=0;
        int l=0;
        int r=0;
        for(int i=0;i<n;i++){
           if(mp.find(s[i])!=mp.end()){
            
            while(l<=mp[s[i]]){
            mp.erase(s[l]);    
            l++;
            }
           }
            ans=max(ans,r-l+1);
            r++;
            mp[s[i]]=i;
        }
        return ans;
    }
};
