class Solution {
private:
bool dfs(int node,vector<int> &vis, vector<int> &pathVis,const vector<int> adj[], stack<int> &st){
    vis[node]=1;
    pathVis[node]=1;
    for(auto i:adj[node]){
        if(!vis[i]){
            if(dfs(i,vis,pathVis,adj,st))return true;
        }else if(pathVis[i]){
            return true;
        }
    }
    pathVis[node]=0;
    st.push(node);
    return false;
}    
public:
    bool canFinish(int n, vector<vector<int>>& preReq) {
        vector<int> adj[n];
        for(auto i:preReq){
            adj[i[1]].push_back(i[0]);
        }
        vector<int>vis(n,0);
        vector<int>pathVis(n,0);
        stack<int>st;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(dfs(i,vis,pathVis,adj,st))return false;
            }
        }
        return st.size()==n;
    }
};
