class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans="";
        int start=0;
        int n1=word1.size();
        int n2=word2.size();
        while(start<min(n1,n2)){
            ans+=(word1[start]);
            ans+=(word2[start]);
            start++;
        }
        while(start<n1){
            ans+=(word1[start]);
            start++;
        }
        while(start<n2){
            ans+=(word2[start]);
            start++;
        }
        return ans;
    }
};