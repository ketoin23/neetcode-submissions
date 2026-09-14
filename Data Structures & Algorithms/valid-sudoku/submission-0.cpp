class Solution {
    bool row(vector<vector<char>> &g) {
        for(int i = 0; i < 9; i++) {
            vector<bool> vis(10, false);
            for(int j = 0; j < 9; j++) {
                if(g[i][j] == '.')
                    continue;
                
                if(vis[g[i][j] - '0'])
                    return false;
                vis[g[i][j] - '0'] = true;
            }
        }
        return true;
    }

    bool col(vector<vector<char>> &g) {
        for(int i = 0; i < 9; i++) {
            vector<bool> vis(10, false);
            for(int j = 0; j < 9; j++) {
                if(g[j][i] == '.')
                    continue;
                
                if(vis[g[j][i] - '0'])
                    return false;
                vis[g[j][i] - '0'] = true;
            }
        }
        return true;
    }

    bool sub(vector<vector<char>> &g, int i, int j) {
        vector<bool> vis(10, false);

        for(int k = i; k < i + 3; k++) {
            for(int l = j; l < j + 3; l++) {
                if(g[k][l] == '.')
                    continue;
                
                if(vis[g[k][l] - '0'])
                    return false;
                
                vis[g[k][l] - '0'] = true;
            }
        }

        return true;
    }

    bool eachSub(vector<vector<char>> &g) {
        for(int i = 0; i < 9; i += 3) {
            for(int j = 0; j < 9; j += 3) {
                if(!sub(g, i, j))
                    return false;
            }
        }

        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return row(board) & col(board) & eachSub(board);
    }
};
