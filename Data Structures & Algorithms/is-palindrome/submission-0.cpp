class Solution {
public:
    bool isPalindrome(string s) {
        string str="abcdefghijklmnopqrstuvwxyzABCDEFZHIJKLMNOPQRSTUVWXYZ0123456789";
        transform(s.begin(),s.end(),s.begin(),::tolower);
        int start=0;
        int end=s.size()-1;
        while(start>=0 && end>=start){
            if(str.contains(s[start]) && str.contains(s[end])){
                if(s[start]!=s[end]){
                    return false;
                }else{
                    start++;
                    end--;
                }
            }else if(!str.contains(s[start])){
                start++;
            }else if(!str.contains(s[end])){
                end--;
            }
        }
        return true;
    }
};
