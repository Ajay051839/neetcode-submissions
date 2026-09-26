class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int>>st;
        int n=temp.size();
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
             ans[i]=0;
            }
            if(!st.empty()&& st.top().first>temp[i]){
                ans[i]=1;
            }else if(!st.empty() && st.top().first<=temp[i]){
                int cnt=1;
                while(!st.empty() && st.top().first<=temp[i]){
                    st.pop();
                }
                if(st.empty())ans[i]=0;
                else{
                    ans[i]=(st.top().second)-i;
                }
            }
            st.push({temp[i],i});
        }
        return ans;
    }
};
