class Solution {
public:
    int calPoints(vector<string>& oper) {
        int ans=0;
        stack<int> st;
        int n=oper.size();
        for(int i=0;i<n;i++){
          if(oper[i]=="+"){
            int num1=st.top();
            st.pop();
            int k=num1+st.top();
            st.push(num1);
            st.push(k);
          }else if(oper[i]=="D"){
            int y=st.top()*2;
            st.push(y);
          }else if(oper[i]=="C"){
            st.pop();
          }else{
            int u=stoi(oper[i]);
            st.push(u);
          }
        }
        while(!st.empty()){
            ans+=(st.top());
            st.pop();
        }
        return ans;
    }
};