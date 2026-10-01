class Solution {
    void f(int ind, vector<int> &v, vector<vector<int>> &res, unordered_map<int, bool> vis, vector<int> &cur) {
        if(ind == v.size()) {
            res.push_back(cur);
            return;
        }

        if(vis[v[ind]]) {
            f(ind +  1, v, res, vis, cur);
            return;
        }

        cur.push_back(v[ind]);
        f(ind + 1, v, res, vis, cur);
        cur.pop_back();

        vis[v[ind]] = true;
        f(ind + 1, v, res, vis, cur);
        vis[v[ind]] = false;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> res;
        unordered_map<int, bool> vis;

        f(0, nums, res, vis, cur);

        return res;
    }
};
