class Solution {
    void transpose(vector<vector<int>> &g) {
        for(int i = 0; i < g.size(); i++) {
            for(int j = i; j < g.size(); j++) {
                swap(g[i][j], g[j][i]);
            }
        }
    }

    void rev(vector<vector<int>> &g) {
        for(auto &i : g) {
            reverse(i.begin(), i.end());
        }
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        rev(matrix);
    }
};
