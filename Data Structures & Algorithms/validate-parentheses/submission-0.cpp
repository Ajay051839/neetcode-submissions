class Solution {
public:
    bool isMatch(char c1,char c2){
        if(c1=='(' && c2==')')return true;
        if(c1=='{' && c2=='}')return true;
        if(c1=='[' && c2==']')return true;
        return false;
    }
    bool isValid(string str) {
       int n=str.size();
       stack<char>st;
       for(int i=0;i<n;i++){
        if(str[i]=='(' || str[i]=='{' || str[i]=='['){
            st.push(str[i]);
        }else{
            if(st.empty())return false;
            char c=st.top();
            if(isMatch(c,str[i])){
                st.pop();
            }else{
                return false;
            }
        }
       }
       return st.empty();
    }
};