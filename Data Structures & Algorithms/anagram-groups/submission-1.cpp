class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //score,index
        unordered_map<int, int>mp;
        vector<vector<string>> ans;
        for(int i=0; i<strs.size(); i++){
            string s=strs[i];
            int score=0;
            for(int j=0; j<s.size(); j++){
               score+=(s[j]-'a'+1);
            }
            if(mp.find(score)!=mp.end()){
                ans[mp[score]].push_back(s);
            }else{
                vector<string>v;
                v.push_back(s);
                ans.push_back(v);
                mp[score]=(ans.size()-1);
            }
        }
        return ans;
    }
};
