class Solution {
public:
    bool validPalindrome(string s) {
        int bal=1;
        int start=0;
        int end=s.size()-1;
        while(start<=end){
            if(s[start]!=s[end]){
                if(s[start+1]==s[end] && bal){
                    bal=0;
                    start=start+2;
                    end--;
                }else if(s[start]==s[end-1] && bal){
                    end=end-2;
                    start++;
                    bal=0;
                }else{
                    return false;
                }
            }else{
                start++;
                end--;
            }
        }
        return true;
    }
};