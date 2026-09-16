class Solution {
public:
    string convertToTitle(int columnNum) {
        string ans="";
        while(columnNum){
            int ld=(columnNum-1)%26;
        
            ans+=('A'+ld);
            
            columnNum=(columnNum-1)/26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    //701-->ld=
};