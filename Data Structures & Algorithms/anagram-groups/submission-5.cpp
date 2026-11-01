class Solution {
public:
    string key(string s){
        sort(s.begin(),s.end());
        return s;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        int n=strs.size();
        for(int i=0;i<n;i++){
          string k=key(strs[i]);
          mp[k].push_back(strs[i]);
        }
        vector<vector<string>>ans;
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};
