class Solution {
    void right(int i, int j, vector<vector<int>> &g, vector<vector<bool>> &vis, vector<int> &res) {
        if(i < 0 || i >= g.size() || j < 0 || j >= g[0].size())
            return;
        if(vis[i][j])
            return;
        
        for(int k = j; k < g[0].size(); k++) {
            if(vis[i][k]) {
                down(i + 1, k - 1, g, vis, res);
                return;
            }

            res.push_back(g[i][k]);
            vis[i][k] = true;
        }

        down(i + 1, g[0].size() - 1, g, vis, res);
    }

    void down(int i, int j, vector<vector<int>> &g, vector<vector<bool>> &vis, vector<int> &res) {
        if(i < 0 || i >= g.size() || j < 0 || j >= g[0].size())
            return;
        if(vis[i][j])
            return;
        
        for(int k = i; k < g.size(); k++) {
            if(vis[k][j]) {
                left(k - 1, j - 1, g, vis, res);
                return;
            }

            res.push_back(g[k][j]);
            vis[k][j] = true;
        }

        left(g.size() - 1, j - 1, g, vis, res);
    }

    void left(int i, int j, vector<vector<int>> &g, vector<vector<bool>> &vis, vector<int> &res) {
        if(i < 0 || i >= g.size() || j < 0 || j >= g[0].size())
            return;
        if(vis[i][j])
            return;
        
        for(int k = j; k >= 0; k--) {
            if(vis[i][k]) {
                up(i - 1, k + 1, g, vis, res);
                return;
            }

            res.push_back(g[i][k]);
            vis[i][k] = true;
        }

        up(i - 1, 0, g, vis, res);
    }

    void up(int i, int j, vector<vector<int>> &g, vector<vector<bool>> &vis, vector<int> &res) {
        if(i < 0 || i >= g.size() || j < 0 || j >= g[0].size())
            return;
        if(vis[i][j])
            return;
        
        for(int k = i; k >= 0; k--) {
            if(vis[k][j]) {
                right(k + 1, j + 1, g, vis, res);
                return;
            }

            res.push_back(g[k][j]);
            vis[k][j] = true;
        }

        right(0, j + 1, g, vis, res);
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<bool>> vis(matrix.size(), vector<bool>(matrix[0].size(), false));
        vector<int> res;

        right(0, 0, matrix, vis, res);

        return res;
    }
};
