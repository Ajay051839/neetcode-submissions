#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<int>st;
        for(int i=0;i<n;i++){
          if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="/" && tokens[i]!="*"){
            int y=std::stoi(tokens[i]);
            st.push(y);
          }else{
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            int c;
            if(tokens[i]=="*"){
               c=(a*b);
            }
            if(tokens[i]=="+"){
               c=(a+b);
            }
            if(tokens[i]=="-"){
               c=(b-a);
            }
            if(tokens[i]=="/"){
               c=(b/a);
            }
            st.push(c);
          }
        }
        return st.top();
    }
};
