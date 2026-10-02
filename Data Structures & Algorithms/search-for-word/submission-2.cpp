class Solution {
    bool f(int i, int j, int n, int m, string &target, int ind, vector<vector<char>> &g, vector<vector<bool>> &vis) {
        if(ind == target.size())
            return true;
        if(i == n || j == m || i == -1 || j == -1)
            return false;
        if(vis[i][j])
            return false;
        
        if(g[i][j] != target[ind]) {
            return false;
        }

        vis[i][j] = true;

        bool a = f(i + 1, j, n, m, target, ind + 1, g, vis);
        bool b = f(i - 1, j, n, m, target, ind + 1, g, vis);
        bool c = f(i, j + 1, n, m, target, ind + 1, g, vis);
        bool d = f(i, j - 1, n, m, target, ind + 1, g, vis);

        vis[i][j] = false;

        return (a | b | c | d);
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool res = false;
        int n = board.size(), m = board[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == word[0]) {
                    vector<vector<bool>> vis(n, vector<bool>(m, false));
                    res = f(i, j, n, m, word, 0, board, vis);
                    if(res)
                        return true;
                }
            }
        }

        return false;
    }
};


