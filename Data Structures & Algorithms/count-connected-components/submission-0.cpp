class Solution {
public:
    void dfs(int node,const vector<int>adj[],vector<int> &vis){
        vis[node]=1;
        for(auto i:adj[node]){
            if(!vis[i]){
                dfs(i,adj,vis);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
      vector<int>adj[n];
      vector<int>vis(n,0);
      int ans=0;
      for(auto i:edges){
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
      }
      for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(i,adj,vis);
            ans++;
        }
      }
      return ans;
    }
};
