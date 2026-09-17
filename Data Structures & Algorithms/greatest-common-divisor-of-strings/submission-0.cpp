class Solution {
   public:
    string constructString(string s,int n){
        string ans="";
        while(n){
            ans+=s;
            n--;
        }
        return ans;
    }
    string gcdOfStrings(string str1, string str2) {
        int n1 = str1.size();
        int n2 = str2.size();
        int k = min(n1, n2);
        for (int i = 0; i < min(n1, n2); i++) {
            for (int j = k; j >= 1; j--) {
                if (n1 % j != 0 || n2 % j != 0) continue;
                if (constructString(str1.substr(i,j),n1/j) == str1 &&
                    constructString(str1.substr(i,j),n2/j) == str2) {
                    return str1.substr(i, j);
                }
            }
        }
        return "";
    }
};