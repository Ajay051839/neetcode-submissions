class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>arr(26,0);
        if(s.size()!=t.size())return false;
        for(int i=0;i<s.size();i++){
          arr[s[i]-'a']++;
          arr[t[i]-'a']--;
        }
        if(arr==vector<int>(26,0))return true;
        return false;
    }
};
