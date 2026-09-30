class Solution {
    void f(vector<int> &cur, vector<bool> &vis, vector<vector<int>> &res, vector<int> &v) {
        if(cur.size() == v.size()) {
            res.push_back(cur);
            return ;
        }

        for(int i = 0; i < v.size(); i++) {
            if(!vis[i]) {
                vis[i] = true;
                cur.push_back(v[i]);
                f(cur, vis, res, v);
                cur.pop_back();
                vis[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> vis(nums.size(), false);
        vector<int> cur;
        f(cur, vis, res, nums);
        return res;
    }
};
