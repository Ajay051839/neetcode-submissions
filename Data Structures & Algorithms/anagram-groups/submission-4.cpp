class Solution {
public:
    int key(string s){
        int ans=0;
        for(auto i:s){
            ans+=(i-'0');
        }
        return ans;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<int,vector<string>>mp;
        int n=strs.size();
        for(int i=0;i<n;i++){
          int k=key(strs[i]);
          mp[k].push_back(strs[i]);
        }
        vector<vector<string>>ans;
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};
