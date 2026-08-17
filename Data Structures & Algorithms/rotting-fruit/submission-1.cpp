class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int time = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int dr[4] = {0, 0, 1, -1};
        int dc[4] = {1, -1, 0, 0};
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 2) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        while (!q.empty()) {
            int level = q.size();
            bool f=false;
            while (level--) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int row = r + dr[k];
                    int col = c + dc[k];
                    if (row >= 0 && row < n && col >= 0 && col < m && grid[row][col] == 1 &&
                        !vis[row][col]) {
                        vis[row][col] = 1;
                        grid[row][col] = 2;
                        f=true;
                        q.push({row, col});
                    }
                }
            }
            if(f)
            time++;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return time;
    }
};
