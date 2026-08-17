class Solution {
private:
int dr[4]={1,0,0,-1};
int dc[4]={0,-1,1,0};    
public:
    void dfs(int r, int c, vector<vector<char>>& grid,vector<vector<int>> &vis, int n, int m){
        vis[r][c]=1;
        for(int i=0; i<4; i++){
            int row=r+dr[i];
            int col=c+dc[i];
            if(row>=0 && row<n && col<m && col>=0 && grid[row][col]=='1' && !vis[row][col]){
                dfs(row,col,grid,vis,n,m);
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    cnt++;
                    dfs(i,j,grid,vis,n,m);
                }
            }
        }
        return cnt;
    }
};
