class Solution {
    int dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<int>> &g) {
        if(i < 0 || j < 0 || i >= g.size() || j >= g[0].size())
            return 0;
        if(vis[i][j])
            return 0;
        if(!g[i][j])
            return 0;
        
        vis[i][j] = true;
        int res = dfs(i + 1, j, vis, g);
        res += dfs(i - 1, j, vis, g);
        res += dfs(i, j + 1, vis, g);
        res += dfs(i, j - 1, vis, g);

        return (1 + res);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(vis[i][j])
                    continue;
                
                int cur = dfs(i, j, vis, grid);
                res = max(res, cur);
            }
        }

        return res;
    }
};
