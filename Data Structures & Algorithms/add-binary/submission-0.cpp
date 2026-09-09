class Solution {
public:
    string addBinary(string a, string b) {
        char carry='0';
        string ans="";
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        for(int i=0;i<max(a.size(),b.size());i++){
            char Ai;
            char Bi;
            if(i>=a.size()){
               Ai='0';
            }else{
                Ai=a[i];
            }
            if(i>=b.size()){
               Bi='0';
            }else{
                Bi=b[i];
            }
            int total=(Ai-'0')+(Bi-'0')+carry-'0';
            int c=total/2;
            carry=c+'0';
            ans=to_string(total%2)+ans;
        }
        if(carry!='0'){
            ans=carry+ans;
        }
        return ans;
    }
};