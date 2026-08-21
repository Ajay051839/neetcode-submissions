class Solution {
public:
    bool isPalindrome(string s,int left, int right){
        while(left<=right){
            if(s[left]!=s[right]){
                return false;
            }else{
                left++;
                right--;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l=0;
        int r=s.size()-1;
        while(l<=r){
            if(s[l]!=s[r]){
                if(isPalindrome(s,l+1,r) || isPalindrome(s,l,r-1))return true;
                else{
                    return false;
                }
            }else{
                l++;
                r--;
            }
        }
        return true;
    }
};