class Solution {
public:
    void Helper(int indx,vector<int>& temp,set<vector<int>>&st,vector<int>& cand,int target,int currSum, int n){
        if(currSum==0){
            st.insert(temp);
            return;
        }
        if(currSum<0 || indx>=n)return;
        temp.push_back(cand[indx]);
        Helper(indx+1,temp,st,cand,target,currSum-cand[indx],n);
        temp.pop_back();
        Helper(indx+1,temp,st,cand,target,currSum,n);

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<int>temp;
        set<vector<int>>st;
        Helper(0,temp,st,candidates,target,target,n);
        return vector<vector<int>>(st.begin(),st.end());
    }
};
