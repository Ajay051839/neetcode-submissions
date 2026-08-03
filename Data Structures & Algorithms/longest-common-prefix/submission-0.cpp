class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int k = INT_MAX;
        for (auto i : strs) {
            int m=i.size();
            k = min(k, m);
        }
        string ans="";
        for (int i = 0; i < k; i++) {
            char c=strs[0][i];
            for (int j = 1; j < n; j++) {
                if(strs[j][i]!=c){
                    return ans;
                }
            }
            ans+=c;
        }
        return ans;
    }
};