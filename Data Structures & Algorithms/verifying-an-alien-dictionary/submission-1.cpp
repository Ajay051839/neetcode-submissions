class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int>mp;
        for(int i=0; i<26; i++){
           mp[order[i]]=(i+1);
        }
        
        for(int i=1;i<words.size();i++){
            bool mismatch=0;
            string str1=words[i-1];
            string str2=words[i];
            int n=str1.size();
            int m=str2.size();
            for(int j=0;j<min(str1.size(),str2.size());j++){
               if(mp[str1[j]]>mp[str2[j]]){
                return false;
               }else if(mp[str1[j]]!=mp[str2[j]]){
                mismatch=1;
                break;
               }
            }
            if(n>m && !mismatch)return false;
        }
        return true;
        
    }
};