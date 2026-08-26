class Solution {
private:
bool dfs(int node, vector<int> &pathVis, vector<int> &vis,const vector<vector<int>>adj, stack<int> &st){
    vis[node]=1;
    pathVis[node]=1;
    for(auto i:adj[node]){
        if(!vis[i]){
            if(dfs(i,pathVis,vis,adj,st))return true;
        }else if(pathVis[i]){
            return true;
        }

    }
    st.push(node);
    pathVis[node]=0;
    return false;
}    
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>>adj(n+1);
        for(auto i:trust){
            adj[i[1]].push_back(i[0]);
        }
        stack<int>st;
        vector<int>vis(n+1,0);
        vector<int>pathVis(n+1,0);
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                if(dfs(i,pathVis,vis,adj,st)){
                    return -1;
                }
            }
        }
        int m=trust.size();
        int k=st.top();
        if(adj[k].size()==(n-1))return st.top();
        return -1;
    }
};