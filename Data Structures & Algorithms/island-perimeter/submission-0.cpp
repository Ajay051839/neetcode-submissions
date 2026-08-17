class Solution {
public:
    int dr[4] = {0, -1, 1, 0};
    int dc[4] = {1, 0, 0, -1};

    void dfs(int r, int c, vector<vector<int>>& vis, vector<vector<int>>& grid, int &ans, int n, int m) {
        vis[r][c] = 1;

        for (int i = 0; i < 4; i++) {
            int row = r + dr[i];
            int col = c + dc[i];

            // If neighbor is water or out-of-bounds, it's a boundary edge
            if (row < 0 || row >= n || col < 0 || col >= m || grid[row][col] == 0) {
                ans++;
            } 
            // If neighbor is unvisited land, explore it recursively
            else if (!vis[row][col]) {
                dfs(row, col, vis, grid, ans, n, m);
            }
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    dfs(i, j, vis, grid, ans, n, m);
                    return ans; // The problem guarantees exactly one island
                }
            }
        }
        return ans;
    }
};