class Solution {
public:

    string freqString(string s){
        int arr[26]={0};
        for(int i=0; i<s.size(); i++){
            arr[s[i]-'a']++;
        }
        string g="";
        char c='a';
        for(int i=0; i<26; i++){
           g+=c; 
           g+=to_string(arr[c-'a']);
           c++;
        }
        return g;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //map -->freq string, string
        unordered_map<string, vector<string>>mp;
        
        for(int i=0; i<strs.size(); i++){
            string k=freqString(strs[i]);
            mp[k].push_back(strs[i]);
        }
        int z=mp.size();
        vector<vector<string>> ans(z);
        int p=0;
        for(auto const& i:mp){
            //vector<string>v=i.second;
            for(auto j:(i.second)){
                ans[p].push_back(j);
            }
            p++;

        }
        
        return ans;
    }
};
