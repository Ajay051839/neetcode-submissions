class Solution {
public:
    int dr[4]={0,-1,1,0};
    int dc[4]={1,0,0,-1};
    void dfs(int r,int c,int n,int m,vector<vector<char>>& board,vector<vector<int>>& vis){ 
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int row=r+dr[i];
            int col=c+dc[i];
            if(row>=0 && row<(n) && col>=0 && col<=(m-1) && !vis[row][col] && board[row][col]=='O'){
             dfs(row,col,n,m,board,vis);
        }
        }

    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if((i==0 || j==0 || i==(n-1) || j==(m-1)) && board[i][j]=='O' && !vis[i][j]){
                    dfs(i,j,n,m,board,vis);
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};
