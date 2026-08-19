class Solution {
   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int dr[4] = {1, 0, 0, -1};
        int cr[4] = {0, 1, -1, 0};

        queue<pair<int,int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    int cnt = 1;
                    vis[i][j] = 1;
                    q.push({i, j});
                    while (!q.empty()) {
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int r = dr[k] + row;
                            int c = cr[k] + col;
                            if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 1 &&
                                !vis[r][c]) {
                                q.push({r, c});
                                cnt++;
                                vis[r][c] = 1;
                            }
                        }
                    }
                    ans = max(ans, cnt);
                }
            }
        }
        return ans;
    }
};
