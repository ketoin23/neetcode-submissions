class Solution {
    void dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<char>> &g) {
        if(i < 0 || j < 0 || i >= g.size() || j >= g[0].size())
            return;
        if(vis[i][j])
            return;
        vis[i][j] = true;
        if(g[i][j] == '0')
            return;
        dfs(i + 1, j, vis, g);
        dfs(i - 1, j, vis, g);
        dfs(i, j + 1, vis, g);
        dfs(i, j - 1, vis, g);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(vis[i][j])
                    continue;
                if(grid[i][j] == '0')
                    continue;
                
                ++res;
                dfs(i, j, vis, grid);
            }
        }

        return res;
    }
};
